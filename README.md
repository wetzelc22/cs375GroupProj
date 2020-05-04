# cs375GroupProj

data_gen.py: Takes four arguments, number of vertices, number of edges per vertice, lowerbound of weight values, upper bound of weight values
It uses these to create random adjacent vertices and random weights between the bound values and creates a text file whose name is specified by vertice count.

run.bat: generates the text files for testing running the data_gen.py 

run2.bat: executes floyd warshall with as many text files as they want

To compile and run: just do "make" to compile necesarry files then run with
./floyd test.txt 1 4 , the 1 and 4 is the two nodes you want to find a shortest path between,  returned after the shortest paths are all found.

floyd.cpp: just has the two functions, one to generate all shortest paths, and one to find a given shortest path between two nodes
