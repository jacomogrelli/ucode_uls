# ULS

Developed by ucode students:
[Oleksiy Nechaiev](nechaeff@gmail.com), [Andrii Ilchuk](https://github.com/ailchuk)

## Description

Implementation of the famous Unix command ```ls```, using the C programming
language. Developed with: 
- MacOS X Mojave 10.14.5 (other OS not tested)
- clang
- GNU make
- VS Code IDE
For each operand that names a file of a type other than directory, ```uls```
displays its name as well as any requested, associated information.  For each
operand that names a file of typedirectory, ```uls``` displays the names of
files contained within that directory, as well as any requested, associated
information.

If no operands are given, the contents of the current directory are displayed.
If more than one operand is given, non-directory operands are displayed first;
directory and non-directory operands are sorted separately and in
lexicographical order.

## how to use:
### Clone repo
https://github.com/jacomogrelli/ucode_uls
### Compilation
make
### Usage:
uls [-AFGRSldmortu1] [file ...]

## Supported flags

|Flag|Description|
|----|------------------------------------------------------------------------|
|```A```|List all entries except for ```.``` and ```..```.|
|```F```|Display a slash (```/```) immediately after each pathname that is a directory, an asterisk (```*```) after each that is executable, an at sign(```@```) after each symbolic link, an equals sign (```=```) after each socket, a percent sign (```%```) after each whiteout, and a vertical bar (```|```)after each that is a FIFO.|
|```G```|Enable colorized output.|
|```R```|Recursively list subdirectories encountered.|
|```S```|Sort files by size.|
|```l```|The lowercase letter ```ell```. List in long format. If the output is to a terminal, a total sum for all the file sizes is output on a line before  the long listing.|
|```d```|Directories are listed as plain files (not searched recursively).|
|```m```|Stream output format; list files across the page, separated by   commas.|
|```o```|List in long format, but omit the group id.|
|```r```|Reverse the order of the sort to get reverse lexicographical order or the oldest entries first (or largest files last, if combined with sort by size.|
|```t```|Sort by time modified (most recently modified first) before sorting  the operands by lexicographical order.|
|```u```|Use time of last access, instead of last modification of the file for sorting (```-t```) or long printing (```-l```).|
|```1```|The numeric digit ```one```. Force output to be one entry per line. This is the default when output is not to a terminal.|
