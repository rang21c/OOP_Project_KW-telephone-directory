# OOP_Project_KW_telephone_directory
### KW 연락처 검색 시스템 - 객체지향프로그래밍 프로젝트

본 프로그램은 파일로부터 주소록 정보와 커맨드 정보를 읽어 Circular linked list 형태로 학과를
구성을 하고, 학과에 따른 해당 학과의 학생의 이름들이 Doubly linked list 형태로 저장되어 있다.
또한 이름에 대해 오름차순으로 Doubly linked list 형태로 연결되어 있다. 이름 Node에는 학년,
학번 그리고 연락처가 각자 다른 Linked list 형태로 연결되어 있음에 유의한다.
![image](https://user-images.githubusercontent.com/33370179/174053682-44985965-de8a-4c61-acf6-abe5ec3b21cb.png)

![image](https://user-images.githubusercontent.com/33370179/174053719-fc4ce8b2-d735-4b46-842b-06c9dc0b74b4.png)

그림 2의 linked list는 해당 학과에 재학중인 어떤 학생들이 있는지를 확인하는 경우 등과 같은 경
우 효율적으로 사용이 가능하며, 그림 3의 linked list는 해당 학과의 재학중인 학생들의 이름, 학번
과 연락처 등의 따라 검색하는데 용이하다.

![image](https://user-images.githubusercontent.com/33370179/174053799-52006f3d-ef1e-4ba1-818f-842ade8e4e30.png)

![image](https://user-images.githubusercontent.com/33370179/174053834-63de1aee-ad34-48a4-8b66-8fb355cbfa3f.png)

Linked list에 사용되는 노드로는 학과 노드(Department Node)와 이름 노드(Name Node)가 있으며
두 노드는 Node를 상속한다. (그림 5. 참조)
학과 노드는 학과 명을 저장하고, 상속 받은 Node의 Pnext는 그림 2의 학과 노드와 연결하며, 마
지막에 연결되어 있는 노드는 Department Node list의 Phead를 가리켜야 한다. Pdown은 그림 2의
하위 정보 노드와 연결되기 위해 사용되며 Pup과 Pprev는 학과 노드에서 사용되지 않는다.
이름 노드는 이름을 저장하며 학년 노드(Grade Node), 학번 노드 (StudentID Node), 그리고 연락
처 노드 (Contact Node)를 가리킨다.

상속받은 Node의 Pup은 그림 2의 위의 학과 노드 또는 이름 노드와 연결하기 위해, Pdown은 아
래의 이름 노드와 연결하기 위해 사용한다. 학과와 학과끼리 연결될 때 그리고 학과와 이름 노드
끼리 연결될 때는 학과명과 학생의 이름은 오름차순으로 정렬되어 삽입된다. 상속받은 Node의
Pnext와 Pprev 노드는 양방향으로 연결되며 이름에 대해 오름차순으로 정렬이 되어있다.
학년 노드(Grade node), 학번 노드(StudentID Node), 그리고 연락처 노드(Contact Node)는 이름 노
드 순서대로 연결 된다. (그림4. 참조)
Node와 Department Node, Name Node간의 구현은 상속 및 다형성 (Polymorphism)을 이용한다.
