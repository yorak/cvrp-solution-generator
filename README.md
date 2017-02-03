# CVRP solution generator
The tool offers three alternative methods to generate or enumerate all possible solutions to a VRP problem. This is a feasible approach to inspect problems smaller than 10 customers. 

Please note that solving CVRPs through enumeration is not an efficient way of solving these problems. This tool was used mainly in visualization of tiny CVRP instances. If you want to solve these problems look into mixed integer programming (MIP), branch-and-bound, column generation and similar combinatorial optimization methods. And if you do not actually need gurarantee the optimality, which is the case in most practical applications, look into construction heuristics, local search heuristics, and metaheuristics. 

The tool is written in C++ for extra speed, but there are surely room to further optimize the procedures if someone requires even better performance. Currently the tool is able to output around 77 000 solutions per wall time second which includes counting of the generated solutions with `wc -l` on Windows 7 and a i5 Dell laptop. By omitting the `PRINT_SOLUTIONS` preprocessing directive and the tool only internally counts the solutions. Then we can enumerate over 5M solutions per wall second. Thus, the generator is heavily bottlenecked by the input/output. It would be trivial to enumerate even faster by making the generators multithreaded. Pull requests implementing this are welcome.

## The generator methods

Of the three the `permutations` based method is the fastest with the `giant_tour` coming as the close second. The `matrix` method is the slowest. A more complete explanation of the methods can be found from the paper Rasku et al. 2013 [1], but the methods are also summarized in the following list. *N* is used to denote the number of customers.
* `permutations` selects all possible (valid) start and end nodes (combinations) for all possible route counts 1..*N*. The remaining points are distributed to the routes in all possible permutations.
* `giant_tours` constructs all hamiltonian cycles and recursively inserts all possible visits to the depot. The visits must fulfill some precendence conditions so that generating the same solution twice is avoided. This is perhaps the cleanest implementation of the three.
* `matrix` uses an alternate encoding of the solutions. A solution is encoded as a binary *N*x*N* matrix where each value decides if a vehicle should travel from the node *i* to node *j*. However, internally the matrix is actually Matt McCutchen's bigint [2] which is usually incremented by one on each step. After each incerement some node connectivity and continuation conditions are checked and some configurations may be skipped to get the first solution that fixes the invalid condition. Each solution candidate that has passed the connectivity conditions is converted to a giant tour encoded solution. However it can be rejected during the conversion if there are subtours (there is a circular route that does not go through the depot). 

## License and disclaimer

This tool is MIT licensed, so use it as you please as long as I get attribution. Also remember that IN NO EVENT SHALL I BE LIABLE TO ANY PARTY FOR DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, INCLUDING LOST PROFITS, ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF REGENTS HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

## Cloning and compiling instructions

Solution and project files are provided for Visual Studio 2013 and Codelite. Before you try to comile, be sure to clone all externals with the repository using the command: `git clone --recursive git://github.com/foo/bar.git`

You need not to use an IDE. You can also just use make by issuing command `make -f vrp_gen.mk`.

## References

[1] Rasku, J., Kärkkäinen, T., Hotokka, P. (2013) Solution Space Visualization as a Tool for Vehicle Routing Algorithm Development. In M. Collan, J. Hämäläinen and P. Luukka (eds.) Proceedings of FORS40 Workshop. 20.-21.8.2013. Lappeenranta, Finland. p. 9-12

[2] McCutchen, M. C++ Big Integer Library. 2010-04-30 version. Available online: https://mattmccutchen.net/bigint/
