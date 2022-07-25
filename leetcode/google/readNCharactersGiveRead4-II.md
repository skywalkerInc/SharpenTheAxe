```c++
/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    char buf4[4];
    int bytesCopied;
    int bytesRead;
    
    Solution() {
        bytesCopied = 0;
        bytesRead = 0;
    }
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int bytesToRead = n;
        int refCount = bytesCopied;
        
        if (bytesRead > bytesCopied) {
            // copy some of already loaded data
            int offset = bytesCopied % 4;
            int size = min(bytesRead-bytesCopied, bytesToRead); //less than 4
            std::memcpy(buf, buf4+offset, size);
            bytesCopied += size;
            bytesToRead -= size;
            cout << buf << endl;
        }
        
        while(bytesRead < bytesCopied + bytesToRead) {
            int readCount = read4(buf4);
            cout << buf4 << " : " << readCount <<endl;
            if (readCount == 0) break;
            bytesRead += readCount;
            
            int offset = bytesCopied % 4;
            int size = min(bytesRead-bytesCopied, bytesToRead); //less than 4
            std::memcpy(buf+(bytesCopied - refCount), buf4+offset, size);
            cout << buf << endl;
            bytesCopied += size;
            bytesToRead -= size;
        }
        
        return bytesCopied - refCount;
        
    }
};

/*
abc
1 2 1
a  | 1
bc | 2
   | 0

buf4 - static

eof

bytesToRead = 1
bytesCopied = 0 (bytesQueried)
bytesRead = 0


buf4
bytesRead - bytesQueried from offset of bytesQuried: available

bytesQueried%4 - offset
copy 
increase bytesQueried

while (buytesRead < bytesQueried + bytesToRead) 
    bytesRead += read(buf4)
    // update buff
    

*/
```