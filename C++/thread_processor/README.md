##Goal##
This program generates a random grid and uses multi-threading to discover how many duplicates there are of a given number by the user by distributing the load of one task across the threads. 

##Outcome##
Implemented using 4 seperate threads to search the array for an O(n^2) runtime

Or can be done using 4 seperate threads to sort the array (merge sort) 
and then find one specified number's duplicates using binary search and 
iteration - for a runtime closer to O(nlog(n)) 
