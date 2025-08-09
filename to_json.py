import os
import json

base_dir = '.'

snippets = {}
for root, dirs, files in os.walk(base_dir):
    absp = os.path.abspath(root)
    if 'lib' in str(absp) or 'stress_test' in str(absp):
        continue
    for file in files:
        if file.endswith('.cpp'):
            file_path = os.path.join(root, file)
            relative_path = os.path.relpath(file_path, base_dir)
            name = os.path.splitext(relative_path.replace(os.sep, '_'))[0]
            
            with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
                content = f.read().replace('\\', '\\\\').replace('"', '\"')
                
                description = ' -> '.join(relative_path.split(os.sep))
                
                snippet = {
                    "prefix": name,
                    "body": [content],
                    "description": f"{description} snippet"
                }
                
                snippets[name] = snippet

json_str = json.dumps(snippets, indent=4, ensure_ascii=False)

with open('temp.json', 'w', encoding='utf-8') as f:
    f.write(json_str)