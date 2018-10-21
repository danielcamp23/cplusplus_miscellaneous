#pragma once
#include <vector>

template <typename T>
class RoundRobin {
public:
	RoundRobin(size_t numAllocator = 0);
	virtual ~RoundRobin();
	RoundRobin(const RoundRobin& src) = delete;
	const RoundRobin& operator = (const RoundRobin& rhs) = delete;
	void add(const T& elem);
	void remove(const T& inElem);
	T& getNext();
private:
	std::vector<T> mElems;
	typename std::vector<T>::iterator mCurElem;/*typename needed whenever you refer to a type based on one or more template params*/
};

template<typename T>
RoundRobin<T>::RoundRobin(size_t numAllocator) {
	mElems.reserve(numAllocator);//This is for performance issues. If wanted, I can especify an allocation for the vector
								// so it won't have to reallocate all the elements after a push_back
	mCurElem = end(mElems); // Initializes the iterator to the end
}

template <typename T>
RoundRobin<T>::~RoundRobin() {}

template <typename T>
void RoundRobin<T>::add(const T& inElem) {
	int pos = (mCurElem != end(mElems) ? mCurElem - begin(mElems) : -1);//Before inserting, I must save the iterator, beacause, if it
																	//reallocates, it might refer to an invalid position in memory
	mElems.push_back(inElem);
	mCurElem = (pos != -1 ? begin(mElems) + pos : end(mElems));
}

template <typename T>
void RoundRobin<T>::remove(const T& inElem) {
	for (auto it = begin(mElems); it != end(mElems); ++it) {
		if (*it == inElem) {
			int newPos;
			if (it < mCurElem) {
				newPos = mCurElem - begin(mElems) - 1;
			}
			else {
				newPos = mCurElem - begin(mElems);
			}

			mElems.erase(it);
			mCurElem = begin(mElems) + newPos;
			return;
		}

	}
}

template <typename T>
T& RoundRobin<T>::getNext() {
	if (mElems.empty()) {
		throw std::out_of_range("No elements in the list");
	}

	if (mCurElem == end(mElems)) {
		mCurElem = begin(mElems);
	}
	else {
		++mCurElem;
		if (mCurElem == end(mElems)) {
			mCurElem = begin(mElems);
		}
	}

	return *mCurElem;
}
