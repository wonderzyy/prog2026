#include <iostream>

#include "queue.h"
#include "stack.h"

using namespace std;

int main()
{
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Stack top = " << st.top() << endl;
    st.pop();
    cout << "Stack top after pop = " << st.top() << endl;
    cout << "Stack size = " << st.size() << endl;

    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Queue front = " << q.front() << endl;
    cout << "Queue back = " << q.back() << endl;
    q.pop();
    cout << "Queue front after pop = " << q.front() << endl;
    cout << "Queue size = " << q.size() << endl;

    return 0;
}
