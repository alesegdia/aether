import os
import subprocess
import tkinter as tk
from tkinter import messagebox

def create_files(base_directory, base_name):
    # Ensure the base directory exists
    if not os.path.exists(base_directory):
        print(f"Error: The directory '{base_directory}' does not exist.")
        return

    # Define file names
    header_file_name = os.path.join(base_directory, f"{base_name}.h")
    cpp_file_name = os.path.join(base_directory, f"{base_name}.cpp")

    # Check if the files already exist
    if os.path.exists(header_file_name) or os.path.exists(cpp_file_name):
        print(f"Error: One or both files already exist:\n- {header_file_name}\n- {cpp_file_name}")
        return

    # Create the .h file
    with open(header_file_name, 'w') as header_file:
        header_content = f"#pragma once\n\n// Header for {base_name}\n\n"
        header_file.write(header_content)
    
    print(f"Header file created: {header_file_name}")

    # Create the .cpp file
    with open(cpp_file_name, 'w') as cpp_file:
        cpp_content = f"#include \"{base_name}.h\"\n\n// Implementation for {base_name}\n"
        cpp_file.write(cpp_content)
    
    print(f"CPP file created: {cpp_file_name}")

def on_submit():
    names = entry.get().split()
    base_directory = "fixed/base/directory"  # Set your fixed base directory here

    for name in names:
        create_files(base_directory, name)

    # Trigger a command after creating the files
    open_file_command = "genie.exe --backend=backend-gl vs2022"
    
    if open_file_command:
        print(f"Executing command: {open_file_command}")
        subprocess.run(open_file_command, shell=True)

    
    messagebox.showinfo("Success", "Files created successfully!")

# Create the main window
root = tk.Tk()
root.title("File Creator")

# Create and place the widgets
tk.Label(root, text="Enter names (separated by space):").pack(pady=10)
entry = tk.Entry(root, width=50)
entry.pack(pady=5)

submit_button = tk.Button(root, text="Create Files", command=on_submit)
submit_button.pack(pady=20)

# Run the application
root.mainloop()