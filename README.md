# Operating-System-Thread-Racing
## Author: Ermias Haile 


## Description: 
create a group of threads and then try to coax them into producing as many race conditions as possible. First, your program should declare a single shared integer variable (i.e. a global variable) with initial value zero; then your program should spawn off the number of threads specified in the source file using the MAXTHREADS defined constant. We will use a for-loop to create these threads. We will designate threads created on even numbered iterations as adders and threads created on odd iterations as subtractors. 



### Adder Threads: (Adding threads WILL have their own thread function)<br/>
Adder threads will execute the following steps:<br/>
1. Read global value and store it into temp<br/>
2. add 3 to the temp value<br/>
3. store temp value into global variable<br/>
4. print the following to the console:<br/>
“Current Value written to Global Variables by ADDER thread id: tid is val” Were tid is the thread id and val is the<br/>
value of  the temporary variable AFTER adding 3 to it.<br/>
5. repeats steps 1 through 4 for MAXITERATIONS (this is a defined constant in the given source code).<br/>



### Subtractor Threads: (Subtracting threads WILL have their own thread function) 
Subtractor threads will execute the following steps:<br/>
1. Read global value and store it into temp <br/>
2. subtract 3 from the temp value <br/>
3. store temp value into global variable <br/>
4. print the following to the console: <br/>
“Current Value written to Global Variables by SUBTRACTOR thread id: tid is val” <br/>
Were tid is the thread id and val is the value of the temporary variable AFTER subtracting 3 from it. <br/>
5. repeats steps 1 through 4 for MAXITERATIONS (this is a defined constant in the given source code). <br/>
Once all threads have finished, please print the value in main in the following way: “Final Value of Shared <br/> 
Variable : val” <br/>
• Where val is the value stored in the shared variable. <br/>
• Make sure to wait for all threads to finish and not just one. <br/>

Since these threads are unsynchronized, there is a possibility of race conditions occurring depending on the actual <br/> interleaved execution order of the various threads. Insert nanosleep() commands into your thread code to induce as many <br/>
race  conditions as possible by forcing an (in)appropriate interleaved execution sequence. <br/>
