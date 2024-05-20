import shutil
import sys
import os

def copy_folder(source, destination):
    # Ensure the source directory exists
    if not os.path.isdir(source):
        print(f"Source directory {source} does not exist.")
        sys.exit(1)
    
    # Ensure the destination directory does not already exist
    if os.path.exists(destination):
        print(f"Destination directory {destination} already exists.")
        sys.exit(1)

    # Perform the copy operation
    try:
        shutil.copytree(source, destination)
        print(f"Successfully copied {source} to {destination}.")
    except Exception as e:
        print(f"Error copying directory: {e}")
        sys.exit(1)

def rename_file(original_file, new_name):    
    # Ensure the new name ends with '.aether'
    if not new_name.endswith('.aether'):
        new_name += '.aether'
    
    # Check if the original file exists
    if not os.path.isfile(original_file):
        print(f"The file {original_file} does not exist.")
        sys.exit(1)
    
    # Check if the new file name already exists to avoid overwriting
    if os.path.isfile(new_name):
        print(f"The file {new_name} already exists.")
        sys.exit(1)
    
    # Rename the file
    try:
        os.rename(original_file, new_name)
        print(f"Successfully renamed {original_file} to {new_name}.")
    except Exception as e:
        print(f"Error renaming file: {e}")
        sys.exit(1)


if __name__ == "__main__":
    # Ensure the correct number of arguments are provided
    if len(sys.argv) != 3:
        print("Usage: python copy_folder.py <destination_directory> <project-name>")
        sys.exit(1)

    destination_dir = sys.argv[1]
    project_name = sys.argv[2]
    project_folder = destination_dir + "/" + project_name

    # Call the function to copy the folder
    copy_folder("./aether-template", project_folder)
    rename_file(project_folder + "/project-name.aether", project_folder + "/" + project_name + ".aether")
