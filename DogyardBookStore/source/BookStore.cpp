//
//  BookStore.cpp
//  BookStore
//  Description CPP file of BookStore Child Class
//  Created by Swasti Gupta on 5/31/15.
//
//

#include "BookStore.h"

/*
 param Container object 
 param member of Container object whose value to be counted.
 Description template function which return the no of encounters 
			of particular member in container object.
 */
template <class ContainerType, class ElementType>
int const count (ContainerType const & container, ElementType const & element){
	int count = 0;
	typename ContainerType::const_iterator i = std::find (container.begin(),
		container.end(), element);
	while (i != container.end()){
		++count;
		i = std::find (++i, container.end(), element);
	}
	return count;
}

/*
 param priceList file path
 Description reads the priceList
 Return returns the GStatus for Success otherwise GParaError for Parameter Error
 */
GStatus BookStore :: readPriceList(char* filename)
{
	ifstream file;
	file.open(filename, ios::in);
	if (!file) {
     return GParamError;
	} 
	string line;
    while (std::getline(file, line))
    {
        if(line != "" && !line.empty())
        {
            std::size_t prev = 0, pos;
            vector <string> wordVector;
            int flag = 1;
            while ((pos = line.find_first_of(",", prev)) != std::string::npos)
            {
                if (pos > prev)
				{
					string word = line.substr(prev, pos-prev);
					if(flag)
					{
						if(word[0] != 'P')
						{
							return GParamError;
						}
						flag = 0;
					}
                    wordVector.push_back(word);
				}
                prev = pos+1;
            }
            if (prev < line.length())
                wordVector.push_back(line.substr(prev, std::string::npos));
            if(wordVector.size() != 3)
            {
                return GParamError;
			}
			if(mBookMap.find(wordVector[0]) != mBookMap.end()) 
			{
				return GParamError;
			}
			Book b(atoi((wordVector[1]).c_str()),wordVector[2].c_str());
			mBookMap[wordVector[0]] = b;
        }
    }
	return GSuccess;
}

/*
 param TransactionList file path
 Description reads the TransactionList file
 Return returns the GStatus for Success otherwise GParaError for Parameter Error
 */
GStatus BookStore:: readTransactionList(char* filename)
{
    ifstream file;
	file.open(filename, ios::in);
	if (!file) {
     return GParamError;
	} 
    string line;
    while (std::getline(file, line))
    {
        if(line != "" && !line.empty())
        {
            std::size_t prev = 0, pos;
            vector <string> wordVector;
			int flag = 1;
            while ((pos = line.find_first_of(",", prev)) != std::string::npos)
            {
                if (pos > prev)
				{
					string word = line.substr(prev, pos-prev);
					if(flag)
					{
						if(word[0] != 'C')
						{
							return GParamError;
						}
						flag = 0;
					}
					else
					{
						if(word[0] != 'P')
						{
							return GParamError;
						}
					}
                    wordVector.push_back(word);
				}
                prev = pos+1;
            }

            if (prev < line.length())
                wordVector.push_back(line.substr(prev, std::string::npos));

			if(wordVector.size() < 2)
			{
				return GParamError;
			}
            vector<string> ::iterator it = wordVector.begin();
            string customerId;
            if(it != wordVector.end())
                customerId.assign(*it);
            it++;
			if(mCustomerMap.find(customerId) == mCustomerMap.end()) 
			{
				Customer customer;
				mCustomerMap[customerId] = customer;
			}
            double sum = 0;
			Transaction trnstion;
            while (it != wordVector.end()) {
                string bookId = *it;
				if(mBookMap.find(bookId) == mBookMap.end()) 
				{
					return GParamError;
				}
				trnstion.addBook(bookId);
				sum += mBookMap[bookId].getPrice();
                it++;
            }
			trnstion.setCustomerId(customerId);
			trnstion.setTransactionAmnt(sum);
			mTransactionList.push_back(trnstion);
        }
    }
	return GSuccess;
}

/*
 Description a structure having comparison fuction for different class objects
 */
struct BookStore:: less_than_key
{
    inline bool operator() (Transaction &obj1, Transaction& obj2)
    {
        if( obj1.getSum()!= obj2.getSum())
            return (obj1.getSum() > obj2.getSum());
        return (obj1.getCustomerId() < obj2.getCustomerId());
    }
    inline bool operator() (pair<string,int> &obj1, pair<string,int> &obj2)
    {
        if( obj1.second != obj2.second)
            return (obj1.second > obj2.second);
        return (obj1.first < obj2.first);
    }
    
};

/*
 param object of type pair <string,int>
 param object of type pair <string,int>
 Description // to compare values frist based on secound key values then first key values
 */
bool BookStore:: compare(pair<string,int>&obj1, pair<string,int>&obj2)
{
    if( obj1.second != obj2.second)
        return (obj1.second < obj2.second);
    return (obj1.first < obj2.first);
}

/*
 param  value of number of top cutomers to be printed 
 Description prints the top n customers based on their no of transactions
 Return returns the GStatus for Success otherwise GParaError for Parameter Error
 */
GStatus BookStore:: findNfrequentCus(int n)
{
    vector<pair<string,int>> customerVisits;
    map<string,Customer> ::iterator itCust = mCustomerMap.begin();
    while(itCust != mCustomerMap.end() )
    {
        int visits = count (mTransactionList, itCust->first);
        customerVisits.push_back(make_pair(itCust->first,visits));
        itCust++;
    }
    sort(customerVisits.begin(), customerVisits.end(), less_than_key());
    vector<pair<string,int>>::iterator it = customerVisits.begin();
    if(it != customerVisits.end() )
    {
        int oldVal = it->second;
        int newVal;
		cout<<endl;
        while (n> 0 && it != customerVisits.end()) {
            newVal = it->second;
            if (oldVal != newVal) {
                n--;
            }
            if (n > 0) {
                cout<<it->first<<" "<<it->second<<",";
            }
            oldVal = newVal;
            it++;
        }
		cout<<endl;
    }
	return GSuccess;
}

/*
 param  value of number of top transactions to be printed 
 Description prints the top n transactions based on their total transaction Amount
 Return returns the GStatus for Success otherwise GParaError for Parameter Error
 */
GStatus BookStore:: findNTopTrans(int n)
{
    sort(mTransactionList.begin(), mTransactionList.end(), less_than_key());
    vector<Transaction>::iterator it = mTransactionList.begin();
    if (it != mTransactionList.end()) {
        double oldVal = it->getSum();
        double newVal ;
		cout<<endl;
        while (n>0 && it != mTransactionList.end()) {
            newVal = it->getSum();
            if (oldVal != newVal) {
                n--;
            }
            if (n > 0) {
                cout<<it->getCustomerId() <<" "<<it->getSum()<<",";
            }
            oldVal = newVal;
            it++;
        }
		cout<<endl;
    }
	return GSuccess;
}

/*
 param  value of number of top books to be printed 
 Description prints the top n books based on their purchases.
 Return returns the GStatus for Success otherwise GParaError for Parameter Error
 */
GStatus BookStore::findNBooks(int n)
{
    int tempN = n;
    vector<pair<string,int>> bookSoldInfo;
    map<string,Book> ::iterator itBookId = mBookMap.begin();
    while (itBookId != mBookMap.end()) {
        int quantity = 0;
        vector<Transaction> ::iterator itList = mTransactionList.begin();
        while (itList != mTransactionList.end()) {
			quantity += count(itList->getPurchasedBookList().begin(), itList->getPurchasedBookList().end(), itBookId->first);
            itList++;
        }
		bookSoldInfo.push_back(make_pair(itBookId->first, quantity));
        itBookId++;
    }
    sort(bookSoldInfo.begin(), bookSoldInfo.end(), less_than_key());
    vector<pair<string,int>>::iterator it = bookSoldInfo.begin();
    if(it != bookSoldInfo.end() )
    {
        int oldVal = it->second;
        int newVal;
        cout<<endl;
        while (n> 0 && it != bookSoldInfo.end()) {
            newVal = it->second;
            if (oldVal != newVal) {
                n--;
            }
            if (n > 0) {
                cout<<it->first<<" "<<it->second<<",";
            }
            oldVal = newVal;
            it++;
        }
		cout<<endl;
    }
    n = tempN;
    sort(bookSoldInfo.begin(), bookSoldInfo.end(), compare);
    it = bookSoldInfo.begin();
    if(it != bookSoldInfo.end() )
    {
        int oldVal = it->second;
        int newVal;
        cout<<endl;
        while (n> 0 && it != bookSoldInfo.end()) {
            newVal = it->second;
            if (oldVal != newVal) {
                n--;
            }
            if (n > 0) {
                cout<<it->first<<" "<<it->second<<",";
            }
            oldVal = newVal;
            it++;
        }
		cout<<endl;
    }
	return GSuccess;
}

/*
 param customerId
 param base Value above which discount available
 param denotes the applicability of discount
 Description the applicability of discount
 Return returns the GStatus for Success otherwise GParaError for Parameter Error
 */
GStatus BookStore::isDiscount(char* custId, double value, int* discount)
{
	if(value < 1)
	{
		return GParamError;
	}
	if(mCustomerMap.find(custId) == mCustomerMap.end()) 
	{
		return GParamError;
	}
    vector<Transaction> :: iterator it = mTransactionList.begin();
    int totalPurchase = 0;
    while (it != mTransactionList.end()) {
        if(it->getCustomerId().compare(custId)== 0)
        {
            totalPurchase += it->getSum();
        }
        it++;
    }
    if (totalPurchase > value) {
        *discount = 1;
    }
    return GSuccess;
}

/*
 param  integer varialble upto which values to be printed
 Description calls the private functions for printing values
 Return returns the GStatus for Success otherwise GParaError for Parameter Error
 */
GStatus BookStore :: getNValues(int n)
{
	if( n <= 0 || mBookMap.size() < n || mTransactionList.size() < n
		|| mCustomerMap.size() < n)
	{
		return GParamError;
	}
	GStatus status;
	status = findNfrequentCus(n);
	if(status != GSuccess)
	{
		return status;
	}
	status = findNTopTrans(n);
	if(status != GSuccess)
	{
		return status;
	}
	status = findNBooks(n);
	if(status != GSuccess)
	{
		return status;
	}
	return GSuccess;
}

