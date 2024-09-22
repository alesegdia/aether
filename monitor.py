import time
import os
import subprocess
import argparse
from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler

class MyHandler(FileSystemEventHandler):
    def __init__(self, command):
        super().__init__()
        self.command = command

    def on_created(self, event):
        if not event.is_directory:
            print(f'File created: {event.src_path}')
            self.execute_command(event.src_path)

    def on_deleted(self, event):
        if not event.is_directory:
            print(f'File deleted: {event.src_path}')
            self.execute_command(event.src_path)

    def execute_command(self, file_path):
        # Replace the command with the file path as an argument
        cmd = f'{self.command} "{file_path}"'
        subprocess.run(cmd, shell=True)

def main(folder_path, command):
    event_handler = MyHandler(command)
    observer = Observer()
    observer.schedule(event_handler, folder_path, recursive=True)

    observer.start()
    print(f'Started monitoring {folder_path} for changes...')

    try:
        while True:
            time.sleep(1)
    except KeyboardInterrupt:
        observer.stop()
    observer.join()

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Monitor a directory for file changes.")
    parser.add_argument('folder', type=str, help='Path to the folder to monitor')
    parser.add_argument('command', type=str, help='Command to execute on file changes')

    args = parser.parse_args()
    main(args.folder, args.command)
