/*
* Given a stream of integers and a window size, 
* calculate the moving average of all integers in the sliding window.
*
**/

class MovingAverage {
public:
    /*
    * @param size: An integer
    */
    MovingAverage(int size) {
        // do intialization if necessary
    	mSize = size;
    	mPrefix = new double[mSize+1];
    	mPrefix[0] = 0.0;
    }

    int mod(int val){
        return val % (mSize+1);
    }
    /*
     * @param val: An integer
     * @return:  
     */
    double next(int val) {
        // write your code here
        ++counter;
        mPrefix[mod(counter)] = mPrefix[mod(counter-1)] + val;
    	if(counter <= mSize){
    		return mPrefix[mod(counter)]/counter;
    	}
    	else{
    		return (mPrefix[mod(counter)] - mPrefix[mod(counter-mSize)])/mSize;
    	}    	
    }
    
   
private:
	int mSize;
	double* mPrefix;
	int counter = 0;
};




/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param = obj.next(val);
 */