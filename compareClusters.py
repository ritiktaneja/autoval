import os

def compare_dir_layout(dir1, dir2):
    def _compare_dir_layout(dir1, dir2):
        for (dirpath, dirnames, filenames) in os.walk(dir1):
            for filename in filenames:
                relative_path = dirpath.replace(dir1, "")
                if os.path.exists( dir2 + relative_path + '\\' +  filename) == False:
                    print (relative_path, filename)
        return

    print ('files in "' + dir1 + '" but not in "' + dir2 +'"')
    _compare_dir_layout(dir1, dir2)
    print ('files in "' + dir2 + '" but not in "' + dir1 +'"')
    _compare_dir_layout(dir2, dir1)