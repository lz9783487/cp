import sys
import os
import hashlib
import subprocess

def get_file_hash(file_path):
    with open(file_path, 'rb') as f:
        file_data = f.read()
        return hashlib.md5(file_data).hexdigest()

def compile_cpp(cpp_file, exe_file, hash_file):
    cpp_hash = get_file_hash(cpp_file)
    exe_hash = ""

    if os.path.isfile(exe_file):
        exe_hash = get_file_hash(exe_file)

    if os.path.isfile(hash_file):
        with open(hash_file, "r") as f:
            content = f.read()
            if cpp_hash + " " + exe_hash in content:
                print("Hash match and skip compile.", end = ' ')
                return # skip
            else:
                print("Hash don't match and recompile.", end = ' ')
    else:
        print("hash file not found and compile.", end = ' ')

    if subprocess.run(["g++", "-O2", "-DLOCAL", "-Wall", "-Wextra", "-pedantic", "-std=c++20", "-Wshadow", "-Wformat=2", "-Wfloat-equal", "-Wconversion", "-Wlogical-op", "-Wcast-qual", "-Wcast-align", "-D_GLIBCXX_DEBUG", "-D_GLIBCXX_DEBUG_PEDANTIC", "-D_FORTIFY_SOURCE=2", "-fstack-protector", cpp_file, "-o", exe_file]).returncode: 
        print("Compile error!") 
        sys.exit(0)

    exe_hash = get_file_hash(exe_file)
    with open(hash_file, "a") as f:
        f.write(f"{cpp_hash} {exe_hash}\n")

def real_execute_program(file_type, exe_file, input_data, output_data):
    argv0 = [exe_file] if file_type == 'cpp' else ['python', exe_file]
    if subprocess.run(argv0, stdin = input_data, stdout = output_data, text = True).returncode:
        print("Runtime Error!")
        sys.exit(0)
    else:
        pass

def execute_program(file_type, exe_file, input_file, output_file):
    print("Execute the program:")
    if input_file:
        with open(input_file, "r") as input_data:
            if output_file:
                with open(output_file, "w") as output_data:
                    real_execute_program(file_type, exe_file, input_data, output_data)
            else:
                real_execute_program(file_type, exe_file, input_data, None)
    else:
        if output_file:
            with open(output_file, "w") as output_data:
                real_execute_program(file_type, exe_file, None, output_data)
        else:
            real_execute_program(file_type, exe_file, None, None)

def shrink_file(file_path, n):
    with open(file_path, 'r') as f:
        lines = f.readlines()

    if len(lines) > n:
        lines = lines[-n:]
    
    with open(file_path, 'w') as f:
        f.writelines(lines)


def main():
    if len(sys.argv) < 2:
        print("Usage: python compile.py <code_file> [input_file] [output_file]")
        sys.exit(1)

    code_file = sys.argv[1]
    input_file = sys.argv[2] if len(sys.argv) >= 3 and sys.argv[2].lower() not in ["none", "no"] else None
    output_file = sys.argv[3] if len(sys.argv) >= 4 and sys.argv[3].lower() not in ["none", "no"] else None
    print(f'input: {input_file}, output: {output_file}.', end = ' ')
    exe_file = os.path.splitext(code_file)[0] + ".exe"
    hash_file = os.path.join(os.path.dirname(__file__), "hashes.txt")

    if not os.path.isfile(code_file):
        print(f"Error: {code_file} not found.")
        sys.exit(1)

    if input_file is not None and not os.path.isfile(input_file):
        print(f"Error: {input_file} not found.")
        sys.exit(1)

    file_type = None
    if code_file.endswith('.cpp'):
        file_type = 'cpp'
        compile_cpp(code_file, exe_file, hash_file)
    elif code_file.endswith('.py'):
        file_type = 'python'
        exe_file = code_file
    else:
        print("Error: Unsupported file type. Only .cpp and .py files are supported.")
        sys.exit(1)

    execute_program(file_type, exe_file, input_file, output_file)

    shrink_file(hash_file, 10)

if __name__ == "__main__":
    main()
