# -*- coding: utf-8 -*-

from math import factorial

def binomial(n, k):
    """binomial(n, k): return the binomial coefficient (n k).
    
    # Knuth calls this the trademark of Binomial
    >>> [binomial( 4, k ) for k in range(5)]
    [1, 4, 6, 4, 1]
    
    >>> binomial( 50, 10 )
    10272278170L
    """
    #assert isinstance(n, (int, long)) and isinstance(k, (int, long))
    if k < 0 or k > n:
        return 0
    if k == 0 or k == n:
        return 1
    return factorial(n) // (factorial(k) * factorial(n-k))


def s1(n, m):
    """
    stirling1 is the number of permutations of n points with k cycles
    
    # Knuth calls this the trademark of S1
    >>> [s1( 4, k ) for k in range(5)]
    [0, -6, 11, -6, 1]
    
    #gap> List( [0..6], n->List( [0..6], k->Stirling1( n, k ) ) );;
    #gap> PrintArray( last );
    #[ [    1,    0,    0,    0,    0,    0,    0 ],    # Note the similarity
    #  [    0,    1,    0,    0,    0,    0,    0 ],    # with Pascal's
    #  [    0,    1,    1,    0,    0,    0,    0 ],    # triangle for the
    #  [    0,    2,    3,    1,    0,    0,    0 ],    # Binomial numbers
    #  [    0,    6,   11,    6,    1,    0,    0 ],
    #  [    0,   24,   50,   35,   10,    1,    0 ],
    #  [    0,  120,  274,  225,   85,   15,    1 ] ]
    
    >>> s1(50,10)
    101623020926367490059043797119309944043405505380503665627365376L
    
    >>> s1(10,7)
    -9450L
    
    """
    sum_k = 0
    for k in xrange(0,n-m+1):
        sum_k += (-1)**k * binomial(n-1+k, n-m+k) * binomial(2*n-m, n-m-k) * s2(n-m+k, k)
    return sum_k
    
    
def s2(n, m):
    """
    Stirling2 is the number of ways to partition a set of n elements into m pairwise disjoint nonempty subsets
    
    # Knuth calls this the trademark of S2
    >>> [s2( 4, k ) for k in range(5)]
    [0, 1, 7, 6, 1]
    >>> [s2(n, m) for n in range(7) for m in range(7)]
    [1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 3, 1, 0, 0, 0, 0, 1, 7, 6, 1, 0, 0, 0, 1, 15, 25, 10, 1, 0, 0, 1, 31, 90, 65, 15, 1]
    >>> s2( 50, 10 )
    26154716515862881292012777396577993781727011L
    >>> s2( 7, 3 )
    301
    """
    sum_k = 0
    for k in xrange(0,m+1):
        sum_k += (-1)**(m-k) * binomial(m, k) * k**n
    return sum_k/factorial(m)
    
    
def b(n):
    """
    http://oeis.org/A003724
    Number of partitions of n-set into odd blocks.
    
    >>> [b(n) for n in range(20)]
    [1, 1, 1, 2, 5, 12, 37, 128, 457, 1872, 8169, 37600, 188685, 990784, 5497741, 32333824, 197920145, 1272660224, 8541537105L, 59527313920L]
    """
    if n==0: return 1
    
    k_sum = 0
    for k in xrange(0,n+1):
        i_sum = 0
        for i in xrange(0,k+1):        
            i_sum += (-1)**i * binomial(k, i)*(k-2*i)**n
        k_sum+=int( i_sum/( 2**k*factorial(k) ) )
        
    return k_sum

def a(n):
    """
    A011800 Number of labeled forests of n nodes each component of which is a path.
    also. Number of solutions for VRP with tour and depot constraints
    
    >>> [a(n) for n in range(3, 10)]
    [7L, 34L, 206L, 1486L, 12412L, 117692L, 1248004L]
    """
    
    k_sum = 0
    for k in xrange(1, n+1):
        #print "loop", k, "of", n+1
        k_sum += abs( s1(n,k) ) * b(k)
    return long(k_sum)

def test():
    toN = 20
    for n in range(toN):
        print n, a(n)
    
def test_s1():
    toN = 9
    
    
    for n in range(1,toN ):
        print '"n=%d"'%n
        #header = ["m\\k"]+["bin1_k=%d bin2_k=%d s2_k=%d"%(k,k,k) for k in range(0,toN)]
        #print " ".join(header)
        print "m s1(n,m) k bin1 bin2 s2"        
        for m in range(n+1):
            for k in range(n-m+1):
                print m, s1(n,m),k, 
                print (-1)**k * binomial(n-1+k, n-m+k),
                print binomial(2*n-m, n-m-k),
                #print "\nDE", n-m+k
                print s2(n-m+k, k)
        print
    
    
def test_a():
    toN = 9
    header = ["n", "a(n)"]+["s1(n,%d)"%k for k in range(0,toN+1)]+["b(%d)"%k for k in range(0,toN+1)]
    print " ".join(header)
    
    for n in range(1,toN ):
        print n,
        print a(n),
        for k in range(toN):
            if k>n+1:
                print ' "n/a"',
            else:
                print s1(n,k),
        for k in range(toN):
            if k>n+1:
                print ' "n/a"',
            else:
                print b(k),
        print 
    return 

def doctestit():
    import doctest
    doctest.NORMALIZE_WHITESPACE = True
    doctest.testmod()
    
def more_than_atoms_in_unverse():
    for i in range(1000):
        if a(i)>4*10**79:
            print i 
            break

if __name__=="__main__":
    #doctestit() #unit testing
    test()
    #print a(385)
    
    