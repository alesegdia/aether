import time
import sys
import subprocess
from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler

class Watcher:
    def __init__(self, directory_to_watch, on_event):
        self.DIRECTORY_TO_WATCH = directory_to_watch
        self.observer = Observer()
        self.on_event = on_event

    def run(self):
        event_handler = Handler(self.on_event)
        self.observer.schedule(event_handler, self.DIRECTORY_TO_WATCH, recursive=True)
        self.observer.start()
        try:
            while True:
                time.sleep(1)
        except KeyboardInterrupt:
            self.observer.stop()
        self.observer.join()

class Handler(FileSystemEventHandler):
    def __init__(self, on_event):
        super().__init__()
        self.on_event = on_event

    def on_created(self, event):
        if event.is_directory:
            print(f"Directory created: {event.src_path}")
        else:
            print(f"File created: {event.src_path}")
        self.on_event(event.src_path, "created")

    def on_deleted(self, event):
        if event.is_directory:
            print(f"Directory deleted: {event.src_path}")
        else:
            print(f"File deleted: {event.src_path}")
        self.on_event(event.src_path, "deleted")

def action_to_execute(path, event_type):
    # Command to execute on file/directory event
    command = "genie.exe --backend=backend-gl vs2022"
    print(f"Executing command: {command}")

    try:
        # Execute the command and capture the output
        result = subprocess.run(command, shell=True, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        output = result.stdout.decode('utf-8')
        error = result.stderr.decode('utf-8')

        if output:
            print(f"Command output: {output}")
        if error:
            print(f"Command error: {error}")
    except subprocess.CalledProcessError as e:
        print(f"Error executing command: {e.stderr.decode('utf-8')}")

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print("Usage: python script.py <directory_to_monitor>")
        sys.exit(1)

    directory_to_monitor = sys.argv[1]
    
    w = Watcher(directory_to_monitor, action_to_execute)
    w.run()
