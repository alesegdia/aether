import sys
import os

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
        cpp_content = f"#include \"{header_file_name}\"\n\n// Implementation for {base_name}\n"
        cpp_file.write(cpp_content)
    
    print(f"CPP file created: {cpp_file_name}")

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python create_files.py <base_directory> <name>")
        sys.exit(1)

    base_directory = sys.argv[1]
    name = sys.argv[2]
    create_files(base_directory, name)
