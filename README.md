# Huffman Code Tree with ASCII Sequence

This code implements a Huffman code tree to encode and decode text using ASCII characters. The program takes a text file as input and generates two output files: `code.txt` and `encodemsg.txt`.
Note that: (i) We use the letter with the smallest ASCII code as the representative of a subtree; (ii) in case of ambiguity, select the two trees with the smallest representatives and when combining the two trees, the one with the smaller representative will be on the left
- `main.cpp`: Contains the main code for executing the Huffman encoding and decoding operations.
- `code.txt`: Output file that stores the Huffman codes for each ASCII character in the input text.
- `encodemsg.txt`: Output file that stores the encoded message using the generated Huffman codes.

## Dependencies

The code requires the following libraries:

- iostream
- string
- unordered_map
- vector
- algorithm
- unordered_set
- fstream
- iomanip

## Usage

1. Compile the code using a C++ compiler.
2. Run the compiled executable with the following command: `./executable_name input_file.txt`.
   - Replace `executable_name` with the name of the compiled executable.
   - Replace `input_file.txt` with the path to the text file containing the input text.

## Code Explanation

The code performs the following steps:

1. Reads the input text from the provided file.
2. Processes the frequency of each ASCII character in the text and creates a vector of Huffman tree nodes based on the frequency.
3. Sorts the vector of nodes based on frequency and ASCII value.
4. Builds a Huffman tree by repeatedly combining the nodes with the lowest frequency.
5. Encodes the input text using the generated Huffman codes.
6. Writes the Huffman codes and the encoded message to the respective output files.

## Code Structure

The code is organized into several functions:

- `structNode`: Creates a new node in the Huffman tree with the provided ASCII character, frequency, left child, and right child.
- `my_compare`: Compares two nodes based on their frequencies and ASCII values.
- `process_frequency`: Processes the frequency of ASCII characters in the input text and creates a vector of nodes based on the frequency.
- `resort`: Sorts and combines the nodes in the vector based on frequency and ASCII value.
- `build_tree`: Builds the Huffman tree by repeatedly resorting and combining the nodes.
- `encode`: Recursively traverses the Huffman tree and generates Huffman codes for each ASCII character.
- `main`: Reads the input text, performs Huffman encoding, and writes the Huffman codes and encoded message to output files.

## Output

The code generates two output files:

- `code.txt`: Contains the Huffman codes for each ASCII character in the input text.
- `encodemsg.txt`: Contains the encoded message using the generated Huffman codes.

Please note that the output files will be created in the same directory as the executable file.

## Example

To run the code, execute the following command in the terminal:

```
./huffman_code input_file.txt
```

Replace `input_file.txt` with the path to your input text file.

After execution, the generated Huffman codes and the encoded message will be stored in the `code.txt` and `encodemsg.txt` files, respectively.
