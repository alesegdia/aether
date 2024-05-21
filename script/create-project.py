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

def replace_string_in_file(file_path, target_string, replacement_string):
    try:
        # Open the file for reading
        with open(file_path, 'r') as file:
            file_contents = file.read()
        
        # Replace the target string with the replacement string
        modified_contents = file_contents.replace(target_string, replacement_string)
        
        # Open the file for writing and save the modified contents
        with open(file_path, 'w') as file:
            file.write(modified_contents)
        
        print(f"Successfully replaced '{target_string}' with '{replacement_string}' in {file_path}")
    except FileNotFoundError:
        print(f"The file {file_path} does not exist.")
    except IOError:
        print(f"An error occurred while reading or writing to the file {file_path}.")

def get_parent_folder_path():
    # Get the absolute path of the script
    script_path = os.path.abspath(__file__)
    
    # Get the directory containing the script
    script_dir = os.path.dirname(script_path)
    
    # Get the parent directory of the script directory
    parent_dir = os.path.dirname(script_dir)
    
    return parent_dir

if __name__ == "__main__":
    # Ensure the correct number of arguments are provided
    if len(sys.argv) != 3:
        print("Usage: python create-project.py <destination_directory> <project-name>")
        sys.exit(1)

    destination_dir = sys.argv[1]
    project_name = sys.argv[2]
    project_folder = destination_dir + "/" + project_name

    # Call the function to copy the folder
    copy_folder("./aether-template", project_folder)
    rename_file(project_folder + "/project-name.aether", project_folder + "/" + project_name + ".aether")

    aether_abs_path = get_parent_folder_path()
    aether_abs_path = aether_abs_path.replace('\\', '\\\\')
    replace_string_in_file(project_folder + "/aether-config.lua", "<AETHER_FULL_PATH>",  aether_abs_path)
    replace_string_in_file(project_folder + "/scripts/genie.lua", "<PROJECT-NAME>",  project_name)
