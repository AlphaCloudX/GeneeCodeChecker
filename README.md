![Logo](https://github.com/AlphaCloudX/GeneeCodeChecker/assets/66267343/86834148-7b72-401d-b089-80a6a3a92914)

# Genee Autograder A2

This has over 1000 possible test cases for CIS1300 Assignment 2: genee

Last updated: Nov 7

## Before Using | Academic Use

This is not the official Autotrader, I may have not got all the edge cases possible but this should test your program extensively regardless.

From UOGuelphs SOCS policies this should be all good to use, this main.c file only contains the test case inputs and the expected outputs. You will not find code that answers any of the given requirements here.

If there are any issues or potential errors, my discord is @alphacloudx, just send a friend request and Ill try to accept asap, my instagram is also @michael_czomko also with msg requests open or just let me know through github by pull requests etc.

## Setting Up The Workspace

To run this script, first, make sure that you are connected to the linux server through ssh

```bash
ssh <username>@linux.socs.uoguelph.ca
```

Once connected, navigate to a folder you would like to work in.
To navigate directories use:

```bash
cd <folderName>
```

To make a new director use

```bash
mkdir <folderName>
```

To view folders or files in your current directory use:

```bash
ls
```

## Downloading

Download the c script using wget using the script below.
This package comes bundled with the school linux server so we do not need to download anything special.

```bash
wget https://raw.githubusercontent.com/AlphaCloudX/GeneeCodeChecker/test-method-9/main.c
```

This will download the main.c file from this repository that has all the test cases

## Compiling

Compiling is simple, just make sure your functions file is in the same directory.
Run this command:

```bash
gcc -Wall -std=c99 main.c lastnameFirstname.c -o testCases.out
```
main.c MUST remain the same but lastnameFirstname.> should be your .c file with all the functions.

To my knowledge, the test script WILL NOT produce any warnings so all warnings present will be from your file. The output is specifically named to testCases.out to prevent it overwriting any files that might already be labeled with a.out.

## Running

Once everything has been compiled, simply run the autograder with this command:

```bash
./testCases.out
```

It should now start testing and after each section ask you to continue.

## In Action:

![image](https://github.com/AlphaCloudX/GeneeCodeChecker/assets/66267343/a6d85306-ae68-44c9-a2da-3615503a1e0c)
<br>After running each prototype test:<br>
![image](https://github.com/AlphaCloudX/GeneeCodeChecker/assets/66267343/ba45400d-2e52-4c2c-9196-f0fb2627a27b)
<br>

## Authors

- [@AlphaCloudX](https://www.github.com/AlphaCloudX)
- [@Moulik](https://github.com/Moulik-Budhiraja)
## Support

Using ssh: https://wiki.socs.uoguelph.ca/techsupport/guides/ssh
