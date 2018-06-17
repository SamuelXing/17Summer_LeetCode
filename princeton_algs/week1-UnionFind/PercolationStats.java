import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;
import edu.princeton.cs.algs4.StdOut;


public class PercolationStats {
	private Percolation perlocation;
	private int trialCount;
	private double[] fractions;
   
   	// perform trials independent experiments on an n-by-n grid
   	public PercolationStats(int n, int trials) {
       	if (n <= 0 || trials <= 0) {
        	throw new IllegalArgumentException("Invalid Arguments");
       	}
       
       	trialCount = trials;
       	fractions = new double[trials];
       	for (int t = 0; t < trialCount; t++) {
        	perlocation = new Percolation(n);
        	while (!perlocation.percolates()) {
            	int i = StdRandom.uniform(1, n+1);
            	int j = StdRandom.uniform(1, n+1);
            	perlocation.open(i, j);
           	}
           	fractions[t] = (double) (perlocation.numberOfOpenSites()/(n*n));
    	}    
   	}  
   	// sample mean of percolation threshold
   	public double mean() {
   		return StdStats.mean(fractions);
   	}
   	// sample standard deviation of percolation threshold
   	public double stddev() {
    	return StdStats.stddev(fractions);
   	}
   	// low  endpoint of 95% confidence interval
   	public double confidenceLo() {
    	return mean() - ((1.96*stddev())/Math.sqrt(trialCount));
   	}
   	// high endpoint of 95% confidence interval
	public double confidenceHi() {
    	return mean() + ((1.96*stddev())/Math.sqrt(trialCount));
   	}              
  	// test client (described below)
   	public static void main(String[] args) {
    	int n = Integer.parseInt(args[0]);
    	int trials = Integer.parseInt(args[1]);
       
       	PercolationStats ps = new PercolationStats(n, trials);
       	String confidence = ps.confidenceLo() + ", " + ps.confidenceHi();
       	StdOut.println("mean                    = " + ps.mean());
       	StdOut.println("stddev                  = " + ps.stddev());
       	StdOut.println("95% confidence interval = " + confidence);
   	}      
}