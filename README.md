orphanlocator
=============

NYUAD Hackathon Team Orphan Locator

Using fuzzy matching and face recognition algorithms, we are able to connect a orphan and his parents. 
When a child goes missing, his parents provide a photo, first name, last name, age, gender, last seen location, and other data on which we perform "fuzzy matching", matching that takes into consideration the variations in data considering time lapses and errors in data entry. Our matching technology allows NGOs or orphanages to find missing kids. Certain identity cards are maintained with full logs of photo, name and other valid details about the missing child. 

Using these two sets of data, (from the parent's side and from the orphanage) a match can be performed that gives approximate prediction value that helps us to understand what is the probability that the child could be the missing one. 

We use Open Source OpenCV algorithms, the Viola-Jones method, Eigen Faces, with Local Binary Pattern Histogram to train the data set, perform face detection and face recognition.  Apart from this fuzzy matching is performed on the additional data so that even without the photo a suitable match can be found. 

Also for further deployment a SMS feature can be developed so that people without access to internet will be able to recieve information about missing children that they reported to the system.
