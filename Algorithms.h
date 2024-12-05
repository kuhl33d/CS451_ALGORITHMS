#ifndef __ALGORITHMS_H__
#define __ALGORITHMS_H__

#pragma once
template <typename T>
class node {
public:
	node() {
		data = new T();
	}
	T* data = nullptr;
	node<T>* nxt = nullptr;
	node<T>* prev = nullptr;
	~node() {
		if (data != nullptr)
			delete data;
	}
};
template <typename T>
class stack {
public:
	node<T>* head = nullptr;
	node<T>* tail = nullptr;
	int size = 0;
	void push(node<T>* pnn) {
		size++;
		if (head == nullptr) {
			head = tail = pnn;
		}
		else {
			tail->nxt = pnn;
			pnn->prev = tail;
			tail = pnn;
		}
	}
	node<T>* pop() {
		size--;
		node* r = head;
		if (head != nullptr) {
			head = head->nxt;
		}
		return r;
	}
	node<T>* get(int i) {
		node<T>* t = this->head;
		for (int j = 0; j < i && t != nullptr; j++) {
			t = t->nxt;
		}
		return t;
	}
};
template <typename T>
class MEMORY
{
private:
	node<T>* head = nullptr;
	node<T>* tail = nullptr;
public:
	int size=-1;//unintialized
	int curr = -1;
	MEMORY(unsigned int size) {
		this->size = size;
	}
	~MEMORY() {
		while (head != nullptr) {
			node<T>* t = this->head->nxt;
			delete head;
			head = t;
		}
	}
	void push(node<T>* pnn) {
		this->curr++;
		if (head == nullptr) {
			head = tail = pnn;
		}
		else {
			tail->nxt = pnn;
			pnn->prev = tail;
			tail = pnn;
		}
	}
	node<T>* pop() {
		this->curr--;
		node<T>* r = head;
		if (head != nullptr) {
			head = head->nxt;
		}
		return r;
	}
	node<T>* _find(int n) {
		node<T>* t = head;
		while (t != nullptr) {
			if (t->data->frame == n) {
				break;
			}
			t = t->nxt;
		}
		return t;
	}
	node<T>* find(node<T>* n) {
		node<T>* t = head;
		while (t != nullptr) {
			if (*(t->data) == *(n->data)) {
				break;
			}
			t = t->nxt;
		}
		return t;
	}
	node<T>* getHead() {
		return head;
	}
	node<T>* get(int i) {
		node<T>* t = this->head;
		for (int j = 0; j < i && t != nullptr; j++) {
			t = t->nxt;
		}
		return t;
	}
	void delete_at(node<T>* n) {
		this->curr--;
		if (n == head && n == tail) {
			head = tail = nullptr;
		}else if (n == head) {
			head = n->nxt;
			if (head != nullptr) {
				head->prev = nullptr;
			}
		}else if (n == tail) {
			if (n->prev != nullptr) {
				tail = n->prev;
				tail->nxt = nullptr;
			}
		}
		else {
			n->prev->nxt = n->nxt;
		}
		//delete n;//no need user will handle
	}
};

struct line
{
	bool reach = false;
	int from = -1;
	int to = -1;
	float dy;
	float dx;
	float m;
	float cx = -1;
	float cy = -1;
	float curr = 0.0f;
	int solution = 0;
	bool intial = false;
	void draw_line(float xs, float ys, float xe, float ye,System::Drawing::Graphics^ g) {
		if (reach == true) {
			g->DrawLine(gcnew System::Drawing::Pen(System::Drawing::Color::White, 2), xs, ys, xe, ye);
		}
		else {
			cx = xs;
			cy = ys;
			dy = ye - ys;
			dx = xe - xs;
			m = dy / dx;
			float limX = xs + (xe - xs) * curr;
			float limY = ys + (ye - ys) * curr;
			while (true)
			{
				if (System::Math::Abs(dx) > System::Math::Abs(dy))
				{
					if (xs < xe)
					{
						cx++;
						cy += m;
						if (cx >= limX) {
							break;
						}
					}
					else
					{
						cx--;
						cy -= m;
						if (cx <= limX) {
							break;
						}
					}
				}
				else
				{
					if (ys < ye)
					{
						cy++;
						cx += 1 / m;
						if (cy >= limY) {
							break;
						}
					}
					else
					{
						cy--;
						cx -= 1 / m;
						if (cy <= limY) {
							break;
						}
					}

				}
				g->FillEllipse(gcnew System::Drawing::SolidBrush(System::Drawing::Color::White), (int)cx - 1, (int)cy - 1, 2, 2);
			}
			if (curr >= 1.0f) {
				reach = true;
			}
		}
	}
};
struct mem_bits {
	int frame;
	unsigned long long bits = 0;
};
#endif // !__ALGORITHMS_H__