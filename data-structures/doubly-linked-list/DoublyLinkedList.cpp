
template <typename T=int>
struct DoublyLinkedListNode {
	T data;
	DoublyLinkedListNode *prev, *next;

	DoublyLinkedListNode(T data, DoublyLinkedListNode *prev=NULL, DoublyLinkedListNode *next=NULL) {
		this->data = data;
		this->prev = prev;
		this->next = next;
	}
};

template <typename T=int>
class DoublyLinkedList {


}
