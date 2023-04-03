#include "Matrix.h"
#include <exception>
using namespace std;
bool sortingCriteria(tuple <int, int, TElem> a, tuple <int, int, TElem> b) {
	if (get<0>(a) == get<0>(b))
		return get<1>(a) < get<1>(b);
	return get<0>(a) < get<0>(b);
}

Matrix::Matrix(int nrLines, int nrCols) {
	   this->cols = nrCols;
	   this->lines = nrLines;
}


int Matrix::nrLines() const {
	return this->lines;
}


int Matrix::nrColumns() const {
	return this->cols;
}


TElem Matrix::element(int i, int j) const {


	TElem result=NULL_TELEM;
	if (i < 0 || i >= this->lines || j < 0 || j >= this->cols)
		throw exception();
	int left = 0;
	int right = this->items.size() - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (get<0>(this->items[mid]) == i && get<1>(this->items[mid]) == j)
			return get<2>(this->items[mid]);
		if (get<0>(this->items[mid]) < i || (get<0>(this->items[mid]) == i && get<1>(this->items[mid]) < j))
			left = mid + 1;
		else
			right = mid - 1;
	}
	return result;
}

TElem Matrix::modify(int i, int j, TElem e) {
	TElem result = NULL_TELEM;
	if (i < 0 || i >= this->lines || j < 0 || j >= this->cols)
		throw exception();
	int left = 0;
	int right = this->items.size() - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (get<0>(this->items[mid]) == i && get<1>(this->items[mid]) == j) {
			result = get<2>(this->items[mid]);
			get<2>(this->items[mid]) = e;
			return result;
		}
		if (get<0>(this->items[mid]) < i || (get<0>(this->items[mid]) == i && get<1>(this->items[mid]) < j))
			left = mid + 1;
		else
			right = mid - 1;
	}
	tuple<int,int,TElem> item = make_tuple(i, j, e);
	this->items.insert(this->items.begin() + left, item);
	return NULL_TELEM;
}


