import subprocess
import itertools
import os

# List all .txt files in current directory
files = [f for f in os.listdir('.') if f.endswith('.txt')]

# Sort for consistent ordering
files.sort()

# Generate all unordered pairs
pairs = list(itertools.combinations(files, 2))

output_filename = "all_results.txt"

with open(output_filename, "w") as out_file:
    out_file.write("Edit Distance Results\n")
    out_file.write("=====================\n\n")

    for f1, f2 in pairs:
        try:
            result = subprocess.run(
                ["python", "main.py", f1, f2],
                capture_output=True,
                text=True,
                check=True
            )

            distance = result.stdout.strip()

            line = f"{f1} vs {f2} : {distance}\n"
            print(line.strip())
            out_file.write(line)

        except subprocess.CalledProcessError as e:
            error_line = f"{f1} vs {f2} : ERROR\n"
            print(error_line.strip())
            out_file.write(error_line)

print("\nAll results saved to all_results.txt")