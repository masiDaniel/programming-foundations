import os

def search_files(directory):
    for entry in os.listdir(directory):
        full_path = os.path.join(directory, entry)
        if os.path.isfile(full_path):
            print(full_path)
        elif os.path.isdir(full_path):
            search_files(full_path)

# Example usage:
directory_to_search = "/path/to/directory"
search_files(directory_to_search)
