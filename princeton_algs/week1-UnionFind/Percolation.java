import edu.princeton.cs.algs4.WeightedQuickUnionUF;

public class Percolation {
    private int size;
    private boolean[][] openSites;
    private WeightedQuickUnionUF uf;
    private int top, bottom, counter;  // virtual nodes
    
    // create n-by-n grid, wi th all sites blocked
    public Percolation(int n) {
        if (n <= 0) { 
            throw new IllegalArgumentException("Invalid Arguments");
        }
        size = n;
        uf = new WeightedQuickUnionUF(n*n+2);
        openSites = new boolean[n][n];
        top = 0;
        bottom = n*n+1;
        counter = 0;
    }
    
    // open site(row, col) if it is not open already
    public void open(int row, int col) {
        if (isOpen(row, col)) {
            return; 
        }
        
        openSites[row-1][col-1] = true;
        counter++;
        
        if (row == 1) {
            uf.union(getIdx(row, col), top);
        }
        if (row == size) {
            uf.union(getIdx(row, col), bottom);
        }
        if (col > 1 && isOpen(row, col-1)) {
            uf.union(getIdx(row, col), getIdx(row, col-1));
        }
        if (row > 1 && isOpen(row-1, col)) {
            uf.union(getIdx(row, col), getIdx(row-1, col));
        }
        if (col < size && isOpen(row, col+1)) {
            uf.union(getIdx(row, col), getIdx(row, col+1));
        }
        if (row < size && isOpen(row+1, col)) {
            uf.union(getIdx(row, col), getIdx(row+1, col));
        }
        
        return;
    }
    
    // is site (row, col) open?
    public boolean isOpen(int row, int col) {
        if (0 < row && row <= size && 0 < col && col <= size) {
            return openSites[row-1][col-1];
        }
        else {
            throw new IllegalArgumentException("Invalid Arguments");
        }
        
    }
    
    // is site(row, col) full?
    public boolean isFull(int row, int col) {
        if (0 < row && row <= size && 0 < col && col <= size) {
            return uf.connected(0, getIdx(row, col));
        }
        else {
            throw new IllegalArgumentException("Invalid Arguments");
        }
    }
    
    // number of open sites
    public int numberOfOpenSites() {
        return counter;
    }
    
    // does the system percolate?
    public boolean percolates() {
        return uf.connected(0, bottom);
    }

    // get idx
    private int getIdx(int row, int col) {
        return (row-1) * size + col;
    }
}