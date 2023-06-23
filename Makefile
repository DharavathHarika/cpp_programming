CC = g++
CFLAGS = -g --std=c++20
OBJS = companydb.o customer.o employee.o person.o purchase.o company.o

all: companydb

companydb: $(OBJS)
	$(CC) -o companydb $(OBJS) $(CFLAGS)

companydb.o: companydb.cpp
	$(CC) -c companydb.cpp $(CFLAGS)

customer.o: customer.cpp customer.h purchase.h
	$(CC) -c customer.cpp $(CFLAGS)

employee.o: employee.cpp employee.h person.h
	$(CC) -c employee.cpp $(CFLAGS)

person.o: person.cpp person.h
	$(CC) -c person.cpp $(CFLAGS)

purchase.o: purchase.cpp purchase.h
	$(CC) -c purchase.cpp $(CFLAGS)

company.o: company.cpp company.h employee.h customer.h
	$(CC) -c company.cpp $(CFLAGS)

clean:
	rm -f companydb $(OBJS)
