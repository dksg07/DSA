# Open and read a CSV file using file handling
filename = "Extracted_Phone_Numbers.csv"

try:
    with open(filename, 'r') as file:
        # Read the header (optional)
        header = file.readline().strip().split(',')
        print("Header:", header)

        # Read the rest of the lines
        for line in file:
            data = line.strip().split(',')  # Split by comma
            print("Row:", data)

except FileNotFoundError:
    print("File not found. Please check the file name or path.")
