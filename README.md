# HTTP
In this programming assignment, you will estimate the minimum number of computers needed
in a web hosting firm so that the average waiting time of a client for each HTTP request does
not exceed a given amount of time.

In order to estimate the minimum number of computers needed, you will be given the logs of
the HTTP requests and use the data to simulate the processing of the requests by the
computers and calculate the average waiting time for the requests. Using the calculated
average waiting time, you will estimate the minimum number of computers needed for the
future.

The log file is stored in a simple text file, which is a Unix-style file, and the end of line character
is denoted by “\n”. The first line of the file gives the number of requests in the log file. The
subsequent lines include the id, priority, request time (denotes the time in milliseconds since
the log file is created) and process time (denotes the processing time of the request in
milliseconds). Each of these are stored as integer numbers and separated by a white space.
