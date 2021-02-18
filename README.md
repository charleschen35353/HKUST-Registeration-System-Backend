Command:

```make``` and run ```./Register```


Index:
1. Elementary data types
2. Doubly-linked list design
3. Hash table design
4. Database management

1. Elementary data types

(I)Basic data
Students, course and course selection data is defined to make the whole programme working.
All of them contains exact the same attributes as required. Also, index class is also
implemented. Index class has a key regarding to its sorting critiria (i.e ID for student
index and code for course index). Each of them points to the course selection data. Thus 
every course selection data is pointed by a student index and a course index.

(II)Operator<
To make the insertion and searching function works more smoothly, for each basic class,
operator< is overloaded. For students, it is determined by the 8-digit numeric ID 
string, compaing its number digit by digit. For course, the value is determined by
the alphabetic order in the first four character of the code. For the rest 3 to 4 
digits of the code, we simply compare its ascii code value (i.e 0<1<A<Z). The value 
of the course data is determined by first, the ID. If the IDs are the same, then compare
the order of the code. For the index, it is compared by the key first (ID for student
and code for course), and then compare the complementary key of the course selection 
data it points to(code for student and ID for course).

2. Doubly-linked list design

(I)Insertion and deletion
In this project, I have implmented a linked list for data storage. For convenience, 
I chose to design a circular doubly-linked list whcih has a dummy node as its pivot,
so therefore all the data can be inserted based on it. Also, tmeplate is used so that
this doubly-linked list can be used with different data types and this improved its
generality. For insertion and deletion, I adopted the trdaditional method which is to
create a new node and plug it into the list. However, in order to make sure that all 
of our data is sorted automatically in the list, whenever the insertion function is 
called, the funciton will compare the value of the input data and the existing in-list
data with operator< (for details of the operator< overloading, please refer to 1.). 
This function will insert new data right to the front of the very first data which makes
the comparsion fail, namely the "bigger value" data. Moreover, to ensure that our remove
function is efficient, I overloaded a function which can directly delete the data when 
providing the address of the target node with the exact data. Details can be found in the
comment of the code.

(II)find
The find function is basically implmented with brute force. We compare the input key to 
all the node in the list, and return the address of the node if found; otherwise, we return
the address of the dummy node. So you may see a lot of use of the dummy node in my code. 
Also, find function is overloaded so that users can easily input the exact object for serach.
Special cases such as student index and course index, since both of them can possess the same
key (i.e ID=00000001 but the pointer to different course seleciton data), so in order to
find the exact index with a ID and the exact course enrolled by the student, users are allowed
to input the ID and Code as two keys, and the find() can return a index pointing to the 
very course selection data.

(III)initialize
For the load function, we have to clean all existing data. Thus an initialize() is provide 
to remove all existing data and turn the whole list back to the very beginning status (i.e
only a dummy node exists). This function is also called in the destructor.

3. Hash table

(I)Hash function
The hash function is implemented with the buckets and base provided by the project description.
Each bucket is a doubly-linked list(see 2.), so it is a array of a doubly-linked list.
To get the exact bucket with a key, hash function is implemented and the serch can be easier. 
To prevent overflow from happening, I chose to adopt long int data type for calculation.
Also, before the adding of the result calculated with the key character, the temporary
sum is moded by the number of bucket.

(II)Insertion and deletion
Not surprising. It is simply done by insert a object into the #index of the list.

(III)Clear
Initialize the table for file loading. It is simply the combination of for loop and the 
initialize function in doubly-linked list as mentioned above.

4. Database management

(I)Deletion of student data or course data
When deleting these two data types, registration and two index databases are also passes
for the synchronization of the data. When a student data is deleted, all registration data
about the student is also deleted. However, when a course is about to be deleted, the 
function will check whether there is an existing registration data of the course by the
index table directly (much faster!). If any student is enrolled, the course can never be 
delete.

(II)HTML
The output of student and course HTML data simply uses a new doubly-linked list to store
the hashtable data since the hashtable manages the data somehow "randomly". By making a
copy of all existing data in the hash table, when inserting them into a temporary lsit, 
since the insert funciton is specialize to keep the order, so the output can easily be
sorted. When dealing with the courses of a student and students of a course, for the 
former one we serach all existing data with Student index so that as soon as a data is
found, it can be printed out directly since it is already sorted. Similarly, the latter
one does the same thing.

(II)FIle IO
Self-define format of file io is used. Details can be found in the code.
