import os
import sys

def search_aether_files(folder):
    """
    Recursively search for .aether files in the given folder.

    :param folder: The root folder to start the search from
    """
    aether_files = []
    for root, _, files in os.walk(folder):
        for file in files:
            if file.endswith('.aether'):
                print(f"Folder {root}")
                aether_files.append(os.path.join(root, file))
    return aether_files

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python search_aether_files.py <folder>")
        sys.exit(1)

    folder = sys.argv[1]

    if not os.path.isdir(folder):
        print(f"The folder {folder} does not exist or is not a directory.")
        sys.exit(1)

    aether_files = search_aether_files(folder)

    if aether_files:
        print("Found .aether files:")
        for file in aether_files:
            print(file)
    else:
        print("No .aether files found.")
