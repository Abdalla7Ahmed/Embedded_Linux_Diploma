#! /usr/bin/python3
import re
from openpyxl import Workbook

def parse_header_file(file_path):
    with open(file_path, 'r') as file:
        content = file.read()
    
    # Regular expression to match function prototypes
    pattern = r'\b\w+\s+(\w+)\s*\([^)]*\)\s*;'
    
    # Find all matches in the content
    matches = re.findall(pattern, content)
    
    return matches

def create_excel_sheet(prototypes):
    workbook = Workbook()
    sheet = workbook.active
    sheet.title = "Function Prototypes"
    
    # Add column headers
    sheet["A1"] = "ID"
    sheet["B1"] = "Function Prototype"
    
    # Fill the sheet with data
    for idx, prototype in enumerate(prototypes, start=1):
        cell_id = f"A{idx + 1}"
        cell_prototype = f"B{idx + 1}"
        
        sheet[cell_id] = f"IDX{idx}"
        sheet[cell_prototype] = prototype
    
    return workbook

def main():
    header_file_path = "header.h"
    
    # Parse header file and get function prototypes
    prototypes = parse_header_file(header_file_path)
    
    # Create Excel sheet and insert data
    workbook = create_excel_sheet(prototypes)
    
    # Save the Excel sheet
    excel_file_path = "function_prototypes.xlsx"
    workbook.save(excel_file_path)
    
    print(f"Function prototypes extracted from '{header_file_path}' and saved to '{excel_file_path}'.")

if __name__ == "__main__":
    main()
