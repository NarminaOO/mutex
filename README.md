## Thread-Safe Queue 
This is a C++ implementation of a thread-safe queue (**threadSafeQ**) using mutex locks.
The code includes a class **threadSafeQ** which encapsulates a queue and ensures thread-safe access to its methods.

## Code explanation
### threadSafeQ Class
The **threadSafeQ** class encapsulates a queue and a mutex to ensure thread-safe access to its methods.

It provides the following methods:

- **retrieveAndDelete():** Retrieves and deletes the front element of the queue.

- **push(int val, int val2, int val3):** Pushes three values into the queue.

- **Print():** Prints the contents of the queue.

### main() Function
The **main()** function demonstrates the usage of the **threadSafeQ** class.

It creates an instance of **threadSafeQ** named q.

Two threads are spawned:

- One thread (**pushThread**) pushes values into the queue using the **push()** method.

- Another thread (**popThread**) retrieves and deletes elements from the queue using the **retrieveAndDelete()** method.

The main thread waits for both threads to finish execution using **join()**.

Finally, the contents of the queue are printed using the **Print()** method.
