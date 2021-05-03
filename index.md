# Unscrambler
A C++ program that creates all possible options of a given word and checks if it is present in the file `words.txt`. In `words.txt` are currently 450k english words stored.

## Installation
<ol>
	<li>Download the <a href="https://github.com/MaFeLP/Unscrambler/release/latest">latest binary release</a> for your platform:</li>
		<ul>
        		<li><code>Unscrambler.exe</code> for Windows-64bit systems</li>
        		<li><code>Unscrambler-Linux</code> for Linux-64bit systems</li>
        		<li><code>Unscrambler-Mac</code> for Intel based Mac systems.</li>
		</ul>
	<li>Download the <code>words.txt</code> file from <a href="https://github.com/MaFeLP/Unscrambler/release/latest">latest release</a> and put it into the same folder, as the binary from step 1.</li>
	<li>Follow the next steps, only if you use windows!</li>
		<ul>
         		<li>Press and hold the <code>windows</code>-key, next to your <code>Ctrl</code>-key.</li>
         		<li>Press the letter <code>R</code> on your keyboard.</li>
         		<li>Release both keys.</li>
         		<li>Empty the box, that popped up in the bottom left corner of your screen.</li>
         		<li>If it is empty, type <code>regedit</code> and then press <code>OK</code>.</li>
         		<li>If asked a user control prompt, click <code>Yes</code>.</li>
         		<li>In the Registry window, you should see a bar on the left ahnd side, like the one in your explorer. In there, navigate to the folder <code>Computer\HKEY_CURRENT_USER\Console</code>. </li>
         		<li>On the right hand side of the window, you should now see many values, having in it <code>ColorTable00</code>, <code>ColorTable01</code>, etc.</li>
         		<li>In the empty white space on the right/middle of this window, make a right click and select <code>New -> DOWRD (32-bit)</code>.</li>
         		<li>If prompted for the name, type <code>VirtualTerminalLevel</code> and press <code>OK</code>.</li>
        		<li>Then Double click the newly created value (should be highlighted blue).</li>
        		<li>A new window should have popped up, asking you for the value.</li>
        		<li>Set the value to <code>1</code> and click <code>OK</code>.</li>
        		<li>You can now close this window.</li>
		</ul>
</ol>

## Executing the program
### Windows
1. Make sure you have the `words.txt` file in the same folder, as `Unscrambler.exe`.
2. Double click the `Unscrambler.exe` file.
3. See [usage](#Usage) for the usage of the program.
4. If the program has outputted all the words,  and said, that it exited, you can continue with Step 5.
5. To close the program, either close the window or type any character and press enter.

### MacOS/Linux
1. Open a terminal.
2. Change the directory with `cd ` to the directory, in which the Binary is located. (You can list all avaliable directories with `ls`).
3. If you are in the directory with the binary and the words.txt file, type `./Unscrambler-Mac` to execute the program.
4. Continue with Usage.

## Usage
1. Execute the program.
2. Type the letters you want to unscramble and then press enter.
3. Type in the number of threads, you want to use and then press enter.
4. Wait for the progress bar to fill and/or the program to say, that it has exited.

## Building from source
⚠️⚠️ Only continue from here, if you know, what you are doing ⚠️⚠️ <br><br>
1. Get the source files by either using git or getting the files, by downloading the zip Archive and extracting it.

```bash
git clone https://github.com/MaFeLP/Unscrambler.git
cd Unscrambler/
```

2. You **can** use the predefined makefile, but it would be better if you would make your own, using cmake.<br>
You can create a makefile, by using the command:

```bash
cmake CMakeLists.txt
```

3. Build the binary with the following command:

```bash
make
```


## Other open source projects used in this project
- [meganz/mingw-std-threads](https://github.com/meganz/mingw-std-threads) - Used for multihreading in windows.
- [ekg/cpp_progress_bar](https://github.com/ekg/cpp_progress_bar) - Used to display the progress bar.
- [dwyl/english-words](https://github.com/dwyl/english-words/) - The dictionary which contains the english words.
