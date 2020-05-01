import sys
import random

def main():
	assert(len(sys.argv) > 1)
	args = str(sys.argv)
	vert_count = int(sys.argv[1])
	num_edges = int(sys.argv[2])
	lower_bound = int(sys.argv[3])
	upper_bound = int(sys.argv[4])

	#create fileid with vert and edge info
	file = str(vert_count) + "_" + str(num_edges) + ".txt"
	fp = open(file, 'w')
	fp.write("start," + str(vert_count)+"\n")

	#create rand adj for each vertex
	count = 0
	while count < vert_count :
		edge_map = {}
		while len(edge_map) != num_edges:
			adj = int(random.uniform(0, vert_count-1) // 1)
			if adj not in edge_map and adj != count:
				edge_map[adj] = int(random.uniform(lower_bound, upper_bound) // 1)
			

		
		#after random adjacency vertices and weights created, write to file for vertex count
		for i in range(vert_count):
			if i in edge_map:
				if(i == vert_count-1):
					fp.write(str(edge_map[i]) + '\n')
				else:
					fp.write(str(edge_map[i]) + ',')
			elif i == count:
				if(i == vert_count - 1):
					fp.write(str(0) + '\n')
				else:
					fp.write(str(0) + ',')
			else:
				if(i == vert_count - 1):
					fp.write(str(-1) + '\n')
				else:
					fp.write(str(-1) + ',')
		count += 1
	fp.close()
	print("File name: " + file)

main()






