using System;//13
using System.Linq;
using System.Collections;
using System.Collections.Generic;

namespace Project1
{
    class Collection<T> : ICloneable, IEnumerable<T>
    {
        public T value; // свойство, которое может хранить значение любого типа (T), который будет указан при создании экземпляра класса. Это позволяет сделать класс более универсальным и гибким в использовании
        public Collection<T> next; // свойство, которое является коллекцией элементов типа T. Оно позволяет связать элементы коллекции между собой, создавая таким образом список или дерево
        private int size; // приватное свойство, которое хранит размер коллекции. Оно используется для отслеживания количества элементов в коллекции

        public Collection()
        {
            value = default(T); // устанавливается значение по умолчанию для типа T (для значимых типов это будет значение, равное нулю, для ссылочных типов — null);
            next = null;  // устанавливается в null, что означает отсутствие следующего элемента в коллекции.   
        }
        public Collection(int capacity) // принимает один параметр capacity типа int
        {
            value = default(T); // устанавливается значение по умолчанию для типа T
            next = null; // устанавливается в null, что означает отсутствие следующего элемента в коллекции
            size = capacity; // устанавливается равным переданному параметру capacity, что позволяет задать начальный размер коллекции
        }
        public Collection(Collection<T> c) // конструктор класса Collection, который принимает один параметр c типа Collection<T>. конструктор позволяет создать новый объект типа Collection, который является копией переданного объекта "c"
        {
            value = c.value; // копируется значение поля value из параметра c
            next = c.next; // копируется значение поля next из параметра c
            size = c.size; // копируется значение поля size из параметра c
        }
        virtual public int Count() // виртуальный публичный метод Count(). Предназначен для подсчёта количества элементов в коллекции
        {
            int count = 0; // Инициализирует переменную count значением 0
            Collection<T> c = this; // Создаёт копию текущего объекта коллекции (this) в переменную c
            while (c != null) // Запускает цикл while, который выполняется до тех пор, пока c не станет равным null.
            {  
                count++; // Увеличивает значение переменной count на 1
                c = c.next; // Перемещается к следующему элементу коллекции, присваивая новое значение c
            }
            return count; // возвращает значение переменной count
        }
        public virtual Collection<T> AddToBeg(T x) // метод AddToBeg, который добавляет элемент x в начало коллекции
        {
            if (this.size != 0 && this.size == Count()) // проверяет, есть ли место в коллекции для добавления нового элемента
            {
                Console.WriteLine("Переполнение коллекции."); // Если коллекция заполнена или её размер равен количеству элементов, выводится сообщение о переполнении коллекции
                return this; // возвращается текущий экземпляр коллекции без изменений
            }
            Collection<T> c = new Collection<T>(); // создаётся новый экземпляр коллекции c
            if (value != null)  // проверяется, есть ли значение в поле value текущего экземпляра коллекции 
            {
                c.next = this; // Если значение есть, оно присваивается полю value нового экземпляра коллекции c
                c.value = x; // текущий экземпляр коллекции становится следующим элементом нового экземпляра коллекции
            }
            else c.value = x; // иначе полю value нового экземпляра коллекции сразу присваивается значение x
            return c; // возвращает новый экземпляр коллекции c
        }
        public virtual Collection<T> AddToEnd(T x) // метод AddToEnd, который добавляет элемент x в конец коллекции
        {
            if (this.size != 0 && this.size == Count()) // проверяет, есть ли место в коллекции для добавления нового элемента
            {
                Console.WriteLine("Переполнение коллекции."); // Если коллекция заполнена или её размер равен количеству элементов, выводится сообщение о переполнении коллекции
                return this; // возвращается текущий экземпляр коллекции без изменений
            }
            if(this.value == null) // проверяется, является ли текущий экземпляр коллекции пустым
            {
                Collection<T> first = this; 
                first.value = x; // элементу x присваивается значение поля value текущего экземпляра коллекции
                return first; // экземпляр возвращается
            }
            Collection<T> c = new Collection<T>(); // создаётся новый экземпляр коллекции c
            Collection<T> beg = this; // 
            Collection<T> r = beg;
            c.value = x; // присваивается значение x
            while (r != null) // обход текущего экземпляра коллекции с помощью цикла while
            { 
                if (r.next == null) // проверяется, является ли следующий элемент коллекции последним
                {
                    r.next = c; // ссылка на новый экземпляр коллекции (c) устанавливается как следующий элемент текущего элемента коллекции
                    return beg; // текущий экземпляр возвращается
                }
                r = r.next; // иначе текущий элемент становится следующим и цикл продолжается
            }
            return beg; // возврат экземпляра без изменений
        }
        public virtual Collection<T> DelElement(T f) // метод DelElement, который удаляет первый элемент из коллекции, равный указанному значению f
        {
            Collection<T> a = new Collection<T>(1); // создаёт новый экземпляр коллекции a с одним элементом 
            a.value = f; // присваивается значение f
            Collection<T> beg = this; // экземпляр коллекции копируется в переменную beg
            if (beg.next == null) // Если следующий элемент текущего экземпляра равен null
            {
                beg = null; // текущий экземпляр устанавливается в null
                return beg; // возврат экземпляра
            }   
            Collection<T> r = beg; // присваивает ссылку на текущий элемент коллекции beg переменной r
            if (string.Compare(beg.value.ToString(), a.value.ToString()) == 0) // проверяет, равен ли первый элемент текущего экземпляра коллекции beg значению a
            {
                value = beg.next.value; // Значение текущего элемента заменяется на значение следующего элемента
                next = beg.next.next; // Ссылка на следующий элемент текущего элемента заменяется на ссылку на следующий элемент следующего элемента
                return this; // Возвращается текущий экземпляр коллекции
            }
            while (r.next != null) // Цикл while продолжает выполняться, пока следующий элемент текущего элемента не станет null
            {
                if (string.Compare(r.next.value.ToString(), a.value.ToString()) == 0) // проверяется, равен ли следующий элемент коллекции заданному значению a
                {
                    if (r.next != null) break; // происходит проверка на null для следующего элемента. Если следующий элемент не null, выполнение цикла прерывается с помощью оператора break
                    else
                    {
                        beg.next = null; // ссылка на следующий элемент первого элемента коллекции устанавливается в null
                        return beg; // возвращается первый элемент
                    }
                }
                r = r.next; // переменная r устанавливается равной следующему элементу
            }
            r.next = r.next.next; // текущий элемент (r) и его следующий элемент (r.next) перемещается на один шаг вперёд
            return beg; // возвращается начальный элемент списка
        }
        virtual public Collection<T> DelElementFromNumber(int d) // метод DelElementFromNumber, который принимает целочисленный аргумент d и удаляет элемент из коллекции, на который указывает d
        {
            if (d <= Count()) // находится ли d в пределах размера коллекции, используя Count()
            {
                Collection<T> beg = this; // создается копия начального элемента
                Collection<T> r = beg; // текущая позиция в списке (r) устанавливается на начало
                for (int i = 0; i < Count(); i++) // цикл for, который проходит по всем элементам коллекции до тех пор, пока не будет достигнут элемент с индексом d-1
                {
                    if (i == d-1)
                    {
                        r.next = r.next.next; //следующий элемент текущего элемента (r.next) устанавливается на следующий за ним элемент (r.next.next), что фактически удаляет элемент из списка
                        return beg; // возвращается начальный элемент (beg)
                    }
                    r = r.next;
                }
            }
            else // Если d выходит за пределы коллекции, выводится сообщение об ошибке и возвращается текущий экземпляр коллекции без изменений
            {
                Console.WriteLine("Выход за пределы коллекции."); 
                return this;
            }
            return this;
        }
        public bool Find(T f) // метод Find, который принимает объект типа T (f) и пытается найти его в коллекции
        {
            Collection<T> a = new Collection<T>(1); // Создается новый экземпляр коллекции a размером 1 элемент
            a.value = f; // элементу присваивается значение f
            Collection<T> x = this; // Текущий элемент коллекции (x) устанавливается на начало (this)
            while (x != null) // Пока x не равен null, выполняется проверка
            {
                if (string.Compare(x.ToString(), a.ToString()) == 0) // Если строки, представляющие текущий элемент (x) и элемент a, равны, проверяется равенство значений элементов
                {
                    if (string.Compare(x.value.ToString(), x.value.ToString()) == 0) return true; // Если значения равны, метод возвращает true
                }
                x = x.next; // Если ни одно из условий не выполнено, x перемещается к следующему элементу (x.next) и процесс повторяется
            }
            return false; // Если элемент не найден, метод возвращает false
        }
        public object Clone() // Метод Clone создаёт новый экземпляр класса Collection<T>, передавая текущий экземпляр класса в конструктор
        {
            return new Collection<T>(this); // создаёт копию текущего объекта, возвращая новый экземпляр класса Collection<T>, который содержит те же данные, что и исходный объект
        }
        public object SurfaceCopy() // Метод SurfaceCopy создает поверхностную копию текущего объекта. Копируются только поля текущего объекта и ссылки на объекты, на которые ссылается текущий объект. Сами объекты не клонируются, а просто копируются ссылки на них.
        {
            return this.MemberwiseClone(); // Метод MemberwiseClone является методом класса Object, от которого наследуются все классы в C#. Он создает поверхностную копию текущего объекта.
        }
        public virtual void Del()
        {
            this.next = null; // полю next присваивается значение null, что означает отсутствие связи с последующим элементом
            this.value = default; // полю value присваивается значение по умолчанию для его типа, что может означать обнуление значения
        }
        public void Print(Collection<T> c) // метод Print, который принимает коллекцию Collection<T> в качестве аргумента
        {
            while (c != null) // цикл while, который продолжается до тех пор, пока коллекция не станет пустой
            {
                string[] data = (c.value.ToString()).Split(' '); // Значение элемента коллекции преобразуется в строку с помощью метода ToString(). Полученная строка разбивается на массив строк с помощью метода Split, используя пробел в качестве разделителя
                { Console.WriteLine("Имя:{0} Фамилия:{1} Пол:{2} Возраст:{3}", data[0],data[1],data[2],data[3]); } // Массив строк используется для вывода значений полей “Имя”, “Фамилия”, “Пол” и “Возраст” с помощью метода Console.WriteLine
                c = c.next; // элемент коллекции перемещается на следующий с помощью присваивания c = c.next
            }
        }
        public void Print (int c)
        {
            Collection<T> x = this; // Создает экземпляр коллекции Collection<T> и присваивает его переменной x, которая инициализируется текущим объектом (this).
            while (c != null) // цикл while, который продолжается до тех пор, пока значение c не станет равным нулю
            {
                if (c == 0)
                {
                    string[] data = (x.value.ToString()).Split(' '); // Строка, представляющая значение элемента коллекции, преобразуется в массив строк с помощью метода Split, используя пробел в качестве разделителя
                    { Console.WriteLine("Имя:{0} Фамилия:{1} Пол:{2} Возраст:{3}", data[0],data[1],data[2],data[3]); } // Значения элементов массива выводятся на экран с помощью метода Console.WriteLine
                }
                x = x.next; // Переменная x обновляется, указывая на следующий элемент коллекции
            }
        }

        IEnumerator IEnumerable.GetEnumerator() // метод возвращает перечислитель, который используется для итерации по коллекции.
        {
            return GetEnumerator();
        }
        virtual public IEnumerator<T> GetEnumerator() // метод GetEnumerator() для интерфейса IEnumerable<T>
        {
            Collection<T> current = this; // сначала создается переменная current, которая указывает на текущий элемент коллекции
            while (current != null) // цикл while, который выполняется до тех пор, пока current не станет равным null
            {
                yield return current.value; // Текущий элемент коллекции возвращается с помощью ключевого слова yield return. Это означает, что элемент будет возвращен при следующем вызове метода MoveNext() на перечислителе.
                current = current.next; // Переменная current обновляется, указывая на следующий элемент коллекции
            }
        }
    }
    class MyEnumerator<T> : IEnumerator<T> // объявляет класс MyEnumerator<T>, который наследуется от интерфейса IEnumerator<T>
    {
        // Класс MyEnumerator<T> содержит две закрытые переменные: beg и current.
        // Обе эти переменные имеют тип Collection<T>, где T — это параметр типа, который будет
        // определен при создании экземпляра класса MyEnumerator<T>.
        Collection<T> beg;
        Collection<T> current;

        // происходит инициализация двух закрытых переменных: beg и current. Им присваивается значение аргумента c, который является коллекцией типа Collection<T>.
        public MyEnumerator(Collection<T> c)
        {
            beg = c;
            current = c;
        }
        object IEnumerator.Current //свойство, которое возвращает текущий элемент коллекции
        {
            get{ return Current;} 
        }
        public T Current
        {
            get {return current.value;}
        }
        public void Reset() // метод, который устанавливает указатель на первый элемент коллекции
        {
            current = this.beg;
        }
        public void Dispose(){ } // метод, используется для освобождения ресурсов, связанных с итератором
        public bool MoveNext() //  метод, который перемещает указатель на следующий элемент коллекции 
        {
            if (current.next == null)
            {
                Reset();
                return false; // возвращает false, если такой не элемент существует
            }
            else 
            {
                current = current.next;
                return true; // возвращает true, если такой элемент существует
            }
        }
    }
    class MyCollection:Collection<Person> // класс MyCollection, который наследуется от класса Collection<Person>
    {
        public MyCollection():base(){}
        public MyCollection(MyCollection c):base(c){}

        public override Collection<Person> AddToBeg(Person x)
        {
            return base.AddToBeg(x); // добавляет элемент x в начало коллекции
        }
        public override Collection<Person> AddToEnd(Person x)
        {
            return base.AddToEnd(x); // добавляет элемент x в конец коллекции
        }
        public override Collection<Person> DelElement(Person f)
        {
            return base.DelElement(f); // удаляет элемент, равный f
        }
        public override Collection<Person> DelElementFromNumber(int j)
        {
            return base.DelElementFromNumber(j); // удаляет элемент с индексом j
        }
        public override void Del()
        {
            base.Del(); // удаляет все элементы из коллекции
        }
        private MyCollection SortName()
        {
            MyCollection m = this; // Создаются две новые коллекции: sorted и x, которая является копией исходной коллекции m
            MyCollection sorted = new MyCollection(); 
            MyCollection x = new MyCollection(m);
            while (x != null) // цикл пока x не станет равен null
            {
                Person min = null; 
                if (x.next == null){ min = x.value; x = null; } // Если x.next равна null, то текущий элемент становится минимальным и x устанавливается в null
                else
                {
                    Collection<Person> c = new MyCollection(x); // Иначе создается новая коллекция c, которая является копией x
                    while (c.next != null) // пока c.next не равна null, выполняется перебор элементов коллекции c и сравнение их имён
                    {
                        for (int i = 0; i < (c.value.name.Length > c.next.value.name.Length ? c.next.value.name.Length:c.value.name.Length);i++) // цикл сравнивается символы имён текущего и следующего элементов
                        {
                            if (c.value.name.ToCharArray()[i] < c.next.value.name.ToCharArray()[i]) // Если символ текущего элемента меньше символа следующего элемента, то текущий элемент становится минимальным и цикл прерывается
                                if (min == null)
                                    {min = c.value; break;}
                                else 
                                    if (c.value.name.ToCharArray()[i] < min.name.ToCharArray()[i]) 
                                { min = c.value; break;}
                                    else break;
                            if (c.value.name.ToCharArray()[i] > c.next.value.name.ToCharArray()[i]) // Если символ текущего элемента больше символа следующего элемента, то следующий элемент становится минимальным и цикл прерывается
                            {
                                if (min == null)
                                    {min = c.next.value;break;}
                                else
                                    if (c.next.value.name.ToCharArray()[i] < min.name.ToCharArray()[i])
                                        {min = c.next.value;break;}
                                    else break;
                            }
                            if (c.value.name.ToCharArray()[i] == c.next.value.name.ToCharArray()[i]) continue; // Если символы равны, то цикл продолжается
                        }
                        c = c.next;
                    }
                }
                sorted.AddToEnd(min); // если минимальный элемент был найден, он добавляется в коллекцию sorted
                if (x != null) // Если минимальный элемент был найден, то он удаляется из коллекции x
                    x.DelElement(min);
            }
            return sorted;
        }
        private MyCollection SortSurname()
        {
            MyCollection m = this; // Создаются три новые коллекции: sorted, x, которая является копией исходной коллекции m, и c, которая является копией x
            MyCollection sorted = new MyCollection(); 
            MyCollection x = new MyCollection(m);
            while (x != null) // цикл пока x не станет равна null
            {
                Person min = null; 
                if (x.next == null){ min = x.value; x = null; } // Если x.next равна null, то текущий элемент становится минимальным и x устанавливается в null
                else
                {
                    Collection<Person> c = new MyCollection(x); // Иначе создается новая коллекция c, которая является копией x
                    while (c.next != null) // пока c.next не равна null, выполняется перебор элементов коллекции c и сравнение их фамилий
                    { 
                        for (int i = 0; i < (c.value.surname.Length < c.next.value.surname.Length ? c.next.value.surname.Length:c.value.surname.Length);i++) // На каждом шаге цикла сравниваются символы фамилий текущего и следующего элементов
                        {
                            if (c.value.surname.ToCharArray()[i] < c.next.value.surname.ToCharArray()[i]) // Если символ текущего элемента меньше символа следующего элемента, то текущий элемент становится минимальным и цикл прерывается
                                if (min == null)
                                    {min = c.value; break;}
                                else 
                                    if (c.value.surname.ToCharArray()[i] < min.surname.ToCharArray()[i])
                                        {min = c.value; break;}
                                    else break;
                            if (c.value.surname.ToCharArray()[i] > c.next.value.surname.ToCharArray()[i]) // Если символ текущего элемента больше символа следующего элемента, то следующий элемент становится минимальным и цикл прерывается
                            {
                                if (min == null)
                                    {min = c.next.value;break;}
                                else
                                    if (c.next.value.surname.ToCharArray()[i] < min.surname.ToCharArray()[i])
                                        {min = c.next.value;break;}
                                    else break;
                            }
                            if (c.value.surname.ToCharArray()[i] == c.next.value.surname.ToCharArray()[i]) continue; // Если символы равны, то цикл продолжается
                        }
                        c = c.next;
                    }
                }
                sorted.AddToEnd(min); // После завершения цикла, если минимальный элемент был найден, он добавляется в коллекцию sorted
                if (x != null) // Если минимальный элемент был найден, то он удаляется из коллекции x
                    x.DelElement(min);
            }
            return sorted;
        }
        private MyCollection SortPosition()
        {
            MyCollection m = this; // Создаются три новые коллекции: sorted, x, которая является копией исходной коллекции m, и c, которая является копией x
            MyCollection sorted = new MyCollection(); 
            MyCollection x = new MyCollection(m);
            while (x != null) // цикл пока x не станет равна null
            {
                Person min = null;
                if (x.next == null){ min = x.value; x = null; } // Если x.next равна null, то текущий элемент становится минимальным и x устанавливается в null
                else
                {
                    Collection<Person> c = new MyCollection(x); // Иначе создается новая коллекция c, которая является копией x
                    while (c.next != null) // пока c.next не равна null, выполняется перебор элементов коллекции c и сравнение их позиций
                    {
                        for (int i = 0; i < (c.value.position.Length > c.next.value.position.Length ? c.next.value.position.Length:c.value.surname.Length);i++) // сравниваются символы позиций текущего и следующего элементов
                        {
                            if (c.value.position.ToCharArray()[i] <= c.next.value.position.ToCharArray()[i]) // Если символ текущего элемента меньше или равен символу следующего элемента, то текущий элемент становится минимальным и цикл прерывается
                                if (min == null)
                                    {min = c.value; break;}
                                else 
                                    if (c.value.position.ToCharArray()[i] < min.position.ToCharArray()[i])
                                        {min = c.value; break;}
                                    else break;
                            if (c.value.position.ToCharArray()[i] > c.next.value.position.ToCharArray()[i]) // Если символ текущего элемента больше символа следующего элемента, то следующий элемент становится минимальным и цикл прерывается
                            {
                                if (min == null)
                                    {min = c.next.value;break;}
                                else
                                    if (c.next.value.position.ToCharArray()[i] < min.position.ToCharArray()[i])
                                        {min = c.next.value;break;}
                                    else break;
                            }
                            if (c.value.position.ToCharArray()[i] == c.next.value.position.ToCharArray()[i]) continue; // Если символы равны, то цикл продолжается
                        }
                        c = c.next;
                    }
                }
                sorted.AddToEnd(min); // если минимальный элемент был найден, он добавляется в коллекцию sorted
                if (x != null) // Если минимальный элемент был найден, то он удаляется из коллекции x
                    x.DelElement(min);
            }
            return sorted;
        }
        private MyCollection SortGender()
        {
            MyCollection m = this; // Создаются три новые коллекции: sorted, x, которая является копией исходной коллекции m, и c, которая является копией x
            MyCollection sorted = new MyCollection(); 
            MyCollection x = new MyCollection(m);
            while (x != null) // пока x не станет равна null
            {
                Person min = null;
                if (x.next == null){ min = x.value; x = null; } // Если x.next равна null, то текущий элемент становится минимальным и x устанавливается в null
                else
                {
                    Collection<Person> c = new MyCollection(x); // Иначе создается новая коллекция c, которая является копией x
                    while (c.next != null) // пока c.next не равна null, выполняется перебор элементов коллекции c и сравнение их полов
                    {
                        if (c.value.gender.ToCharArray()[0] <= c.next.value.gender.ToCharArray()[0]) // Если символ текущего элемента меньше или равен символу следующего элемента, то текущий элемент становится минимальным и цикл прерывается
                            if (min == null)
                                min = c.value;
                            else 
                                if (c.value.gender.ToCharArray()[0] < min.gender.ToCharArray()[0])
                                    min = c.value;
                        if (c.value.gender.ToCharArray()[0] > c.next.value.gender.ToCharArray()[0]) // Если символ текущего элемента больше символа следующего элемента, то следующий элемент становится минимальным и цикл прерывается
                        {
                            if (min == null)
                                min = c.next.value;
                            else
                                if (c.next.value.gender.ToCharArray()[0] < min.gender.ToCharArray()[0])
                                    min = c.next.value;
                        }
                        c = c.next;
                    }
                }
                sorted.AddToEnd(min); // если минимальный элемент был найден, он добавляется в коллекцию sorted
                if (x != null) // Если минимальный элемент был найден, то он удаляется из коллекции x
                    x.DelElement(min); 
            }
            return sorted;
        }
        private MyCollection SortAge()
        {
            MyCollection m = this; // Создаются три новые коллекции: sorted, x, которая является копией исходной коллекции m, и c, которая является копией x
            MyCollection sorted = new MyCollection(); 
            MyCollection x = new MyCollection(m);
            while (x != null) // пока x не станет равна null
            {
                Person min = null;
                if (x.next == null){ min = x.value; x = null; } // Если x.next равна null, то текущий элемент становится минимальным и x устанавливается в null
                else
                {
                    Collection<Person> c = new MyCollection(x); // Иначе создается новая коллекция c, которая является копией x
                    while (c.next != null) // пока c.next не равна null, выполняется перебор элементов коллекции c и сравнение их возрастов
                    {
                        if (c.value.age < c.next.value.age) // Если возраст текущего элемента меньше возраста следующего элемента, то текущий элемент становится минимальным и цикл прерывается
                        {
                            if (min == null)
                                min = c.value;
                            else 
                                if (c.value.age < min.age) 
                                min = c.value;
                        }
                        else                               // Если возраст текущего элемента больше или равен возрасту следующего элемента, то следующий элемент становится минимальным и цикл прерывается
                        {
                            if (min == null)
                                min = c.next.value;
                            else
                                if (c.next.value.age < min.age)
                                    min = c.next.value;
                        }
                        c = c.next;
                    }
                }
                sorted.AddToEnd(min); // если минимальный элемент был найден, он добавляется в коллекцию sorted
                if (x != null) // Если минимальный элемент был найден, то он удаляется из коллекции x
                    x.DelElement(min);
            }
            return sorted;
        }
        public MyCollection Sort(int i) // Метод Sort(int i) предназначен для сортировки коллекции по различным критериям
        {
            if (i == 1) return SortPosition(); // сортировка по позиции
            if (i == 2) return SortName(); // сортировка по имени
            if (i == 3) return SortSurname(); // сортировка по фамилии
            if (i == 4) return SortGender(); // сортировка по полу
            if (i == 5) return SortAge(); // сортировка по возрасту
            else {Console.WriteLine("Неверный параметр."); return this; } // Если значение параметра i не соответствует ни одному из указанных критериев, выводится сообщение «Неверный параметр»
        }
        public int Length // Свойство Length возвращает количество элементов в коллекции
        {   
            get {return Count();}
        }
        public override IEnumerator<Person> GetEnumerator() // Метод GetEnumerator() возвращает перечислитель, который позволяет перебрать все элементы коллекции
        {
            return base.GetEnumerator();
        }
    }
    class NewMyCollection:MyCollection
    {
        public string NameCollection{get; set; } // хранит строку, которая используется для идентификации коллекции
        public delegate void CollectionHandler(object source, CollectionHandlerEventArgs args); // Делегат CollectionHandler — определяет сигнатуру метода, который будет вызываться при изменении коллекции
        public event CollectionHandler CollectionCountChanged; // позволяет отслеживать изменения количества элементов в коллекции
        public event CollectionHandler CollectionReferenceChanged; // позволяет отслеживать ссылки на элементы
        public virtual void OnCollectionCountChanged(object source, CollectionHandlerEventArgs args) // вызывает события при изменении количества элементов в коллекции
        {
            if (CollectionCountChanged != null)
                CollectionCountChanged(source,args);
        }
        public virtual void OnCollectionReferenceChanged(object source, CollectionHandlerEventArgs args) // вызывает события при изменении ссылки на элементы
        {
            if (CollectionReferenceChanged != null)
                CollectionReferenceChanged(source, args);
        }
        public override Collection<Person> AddToEnd(Person x) // добавляют элемент в конец коллекции
        {
            OnCollectionCountChanged(this, new CollectionHandlerEventArgs(NameCollection, "добавление в конец коллекции", x));
            return base.AddToEnd(x);
        }
        public override Collection<Person> AddToBeg(Person x) // добавляют элемент в начало коллекции
        {
            OnCollectionCountChanged(this, new CollectionHandlerEventArgs(NameCollection, "добавление в начало коллекции", x));
            return base.AddToBeg(x);
        }
        public bool Remove(int j) // метод Remove(int j), который удаляет элемент из коллекции по индексу j
        {
            if (0 < j && j <= Length) 
            {
                OnCollectionCountChanged(this, new CollectionHandlerEventArgs(NameCollection, "удаление", this[j])); // создается экземпляр CollectionHandlerEventArgs с информацией о типе изменения («удаление») и элементе, который был удален
                DelElementFromNumber(j); // вызывается метод DelElementFromNumber(j), который выполняет фактическое удаление элемента из коллекции
                return true; // метод возвращает true
            }
            return false; // если индекс j выходит за пределы допустимого диапазона, метод возвращает false
        }
        public Person this[int index]
        {
            get 
            {
                Collection<Person> x = this; // Создаёт локальную переменную x, которая ссылается на текущий объект
                for (int i = 0; i < Length &&  i != index; i++) // цикл, который перебирает элементы коллекции до тех пор, пока не будет найден нужный индекс
                {
                    x = x.next;
                }
                return x.value; // Возвращает значение поля value элемента
            }
            set 
            {   
                OnCollectionReferenceChanged(this, new CollectionHandlerEventArgs(NameCollection, "изменение", this[index])); // Вызывает событие OnCollectionReferenceChanged, чтобы уведомить об изменении ссылки на элемент
                Collection<Person> x = this; // Создаёт локальную переменную x, которая ссылается на текущий объект
                for (int i = 0; i < Length &&  i == index; i++) // цикл, который перебирает элементы коллекции до тех пор, пока не будет найден нужный индекс
                {
                    x = x.next;
                }
                x.value = value; // Устанавливает значение поля value элемента
            }
        }
    }
    class CollectionHandlerEventArgs:System.EventArgs // класс CollectionHandlerEventArgs, который наследуется от класса System.EventArgs
    {
        public string name_collection{get;set; } // строка, содержащая имя коллекции, с которой связано событие;
        public string event_type{get;set; } // строка, содержащая тип события
        public Person element{get;set; } // объект типа Person, представляющий элемент коллекции

        public CollectionHandlerEventArgs(string input_name_collection, string input_event_type, Person input_col)
        {
            name_collection = input_name_collection; // строка, содержащая имя коллекции
            event_type = input_event_type; // строка, содержащая тип события
            element = input_col; // объект типа Person, представляющий элемент коллекции
        }

    }
    class Journal
    {
        public string name_collection{get;set; } // строка, представляющая название коллекции
        public string event_type{get;set; } // строка, представляющая тип события
        public string data {get;set; } // строка, содержащая дополнительные данные
        public List<Journal> journal { get; set; } // список объектов типа Journal, который является коллекцией журналов

        public Journal() // создаёт пустой список журналов
        {
            journal = new List<Journal>();
        }
        public Journal(string input_name_collection, string input_event_type, string intput_data) // инициализирует свойства name_collection, event_type и data значениями, переданными в качестве аргументов, а также создаёт пустой список журналов
        {
            name_collection = input_name_collection;
            event_type = input_event_type;
            data = intput_data;
        }
        public override string ToString() // проверяет тип события (event_type) 
        {
            string from;
            if (event_type.Contains("добавление"))
                from = " в коллекцию ";
            else if (event_type.Contains("изменение"))
                from = " в коллекции ";
            else
                from = " из коллекции ";
            return event_type + " " + data + from + name_collection;
        }

        public void CollectionCountChanged(object source, CollectionHandlerEventArgs args) // source (объект, вызвавший событие) и args (экземпляр класса CollectionHandlerEventArgs, который содержит информацию о событии)
        {
            Journal j = new Journal(args.name_collection,args.event_type, args.element.ToString()); // Экземпляр Journal создаётся с использованием данных, полученных из args: args.name_collection, args.event_type и args.element.ToString()
            journal.Add(j);
        }
        public void CollectionReferenceChanged(object source, CollectionHandlerEventArgs args) // source (объект, вызвавший событие) и args (экземпляр класса CollectionHandlerEventArgs, который содержит информацию о событии)
        {
            Journal j = new Journal(args.name_collection,args.event_type, args.element.ToString()); // Экземпляр Journal создаётся с использованием данных, полученных из args: args.name_collection, args.event_type и args.element.ToString()
            journal.Add(j); 
        }
    }
    class Person
    {
        public string name;
        public string surname;
        public string gender;
        public int age;
        public string position;

        public Person() // присваивает всем свойствам класса значения по умолчанию: null для строк и 0 для числа
        {
            name = null;
            surname = null;
            gender = null;
            age = 0;
        }

        public Person(string name_input, string surname_input, string gender_input, int age_input) // принимает четыре аргумента и присваивает их соответствующим свойствам класса
        {
            name = name_input;
            surname = surname_input;
            gender = gender_input;
            age = age_input;
        }

        public Person GenericPerson()
        {
            string[] male_name_list = new string[10] {"Liam","Noah","Oliver","Elijah","Jamse","William","Benjamin","Lucas","Henry","Theodore"};
            string[] femaly_name_list = new string[10] {"Olivia","Emma","Charlotte","Amelia","Ava","Sophia","Isabella","Mia","Evelyn","Harper"};
            string[] surname_list = new string[10] {"Smith","Johnson","Williams","Brown","Jones","Garcia","Miller","Davis","Rodriguez","Martinez"};
            Random rnd = new Random();
            int info = rnd.Next(1,4);
            switch (info)
            {
                case 1:
                    info = rnd.Next(1,3);
                    if (info == 1)
                    {
                        return new Employee(male_name_list[rnd.Next(0,10)],surname_list[rnd.Next(0,10)], "M", rnd.Next(20,50));
                    }
                    else if (info == 2)
                    {
                        return new Employee(femaly_name_list[rnd.Next(0,10)],surname_list[rnd.Next(0,10)], "W", rnd.Next(20,50));
                    }
                    break;
                case 2:
                    info = rnd.Next(1,3);
                    if (info == 1)
                    {
                        return new Worker(male_name_list[rnd.Next(0,10)],surname_list[rnd.Next(0,10)], "M", rnd.Next(20,50));
                    }
                    else if (info == 2)
                    {
                        return new Worker(femaly_name_list[rnd.Next(0,10)],surname_list[rnd.Next(0,10)], "W", rnd.Next(20,50));
                    }
                    break;
                case 3:
                    info = rnd.Next(1,3);
                    if (info == 1)
                    {
                        return new Enginer(male_name_list[rnd.Next(0,10)],surname_list[rnd.Next(0,10)], "M", rnd.Next(20,50));
                    }
                    else if (info == 2)
                    {
                        return new Enginer(femaly_name_list[rnd.Next(0,10)],surname_list[rnd.Next(0,10)], "W", rnd.Next(20,50));
                    }
                    break;
                default:
                    return null;
            }
            return null;
        }

        virtual public void Print()
        {
            Console.WriteLine("Имя:{0}      Фамилия:{1}     Пол:{2}     Возраст:{3}", name, surname, gender, age);
        }

        public override string ToString()
        {
            return name + " " + surname + " " + gender + " " + age.ToString();
        }
    }
    class Employee:Person
    {
        public Employee():base(){position = "Служащий";}
        public Employee(string name_input, string surname_input, string gender_input, int age_input):base(name_input, surname_input, gender_input, age_input){position = "Служащий";}

        public override void Print()
        {
            Console.WriteLine("{0}: Имя:{1}      Фамилия:{2}     Пол:{3}     Возраст:{4}", position, name, surname, gender, age);
        }
    }
    class Worker:Person
    {
        public Worker():base(){position = "Рабочий";}
        public Worker(string name_input, string surname_input, string gender_input, int age_input):base(name_input, surname_input, gender_input, age_input){position = "Рабочий";}

        public override void Print()
        {
            Console.WriteLine("{0}: Имя:{1}      Фамилия:{2}     Пол:{3}     Возраст:{4}", position, name, surname, gender, age);
        }
    }
    class Enginer:Person
    {
        public Enginer():base(){position = "Инженер";}
        public Enginer(string name_input, string surname_input, string gender_input, int age_input):base(name_input, surname_input, gender_input, age_input){position = "Инженер";}

        public override void Print()
        {
            Console.WriteLine("{0}: Имя:{1}      Фамилия:{2}     Пол:{3}     Возраст:{4}", position, name, surname, gender, age);
        }
    }

    internal class Program
    {
        static int Menu(int m)
        {
            if (m == 0)
            {
                Console.WriteLine("1. Печать коллекции.");
                Console.WriteLine("2. Добавить элемент в коллекциию.");
                Console.WriteLine("3. Удалить элемент из коллекии.");
                Console.WriteLine("4. Изменить элемент в коллекции.");
                Console.WriteLine("5. Выход.");
            }
            if (1 <= m && m <= 4) {Console.Write("Введите имя коллекции:"); return m = 0;}
            return m = Convert.ToInt32(Console.ReadLine());
        }
        static void Creat(ref NewMyCollection col)
        {
            Person a = new Person();
            Console.Write("Количество элементов в коллекции:");
            int size = Convert.ToInt32(Console.ReadLine());
            Console.Write("Введеите имя коллекции:");
            col.NameCollection = Console.ReadLine();
            for (int i = 0; i < size; i++) // выполняется size итераций, на каждой из которых вызывается метод AddToEnd для добавления нового элемента в коллекцию col
            {
                col.AddToEnd(a.GenericPerson());
            }
        }
        void CreatJornal()
        {

        }
        static void PrintCollection(NewMyCollection col)
        {
            Console.WriteLine("Содержание коллекции {0}:",col.NameCollection);
            foreach (Person x in col)
            {
                x.Print();
            }
        }
        static void AddCollection(ref NewMyCollection col)
        {

        }
        static void DelElementFromCollection(ref NewMyCollection col)
        {
            Console.Write("Введите номер для удаления:");
            int j = Convert.ToInt32(Console.ReadLine());
            if (col.Remove(j))
                Console.WriteLine("Элемент удален.");
            else
                Console.WriteLine("Ошибка. Элемент не найден.");
        }
        static void TransformDataCollection(ref NewMyCollection col)
        {
            Console.Write("Введите номер для изменения:");
            int j = Convert.ToInt32(Console.ReadLine());
            if (0 <= j && j < col.Length)
            {
                Person a = new Person();
                col[j] = a.GenericPerson();
            }
            else Console.WriteLine("Выход за пределы коллекции.");
        }
        static void PrintJournal (Journal j)
        {
            foreach(Journal x in j.journal)
                Console.WriteLine(x.ToString());
        }
        static void Main (string[] args) 
        {
            bool status = true;
            NewMyCollection col1 = new NewMyCollection(); // Создаёт две коллекции col1 и col2 типа NewMyCollection
            NewMyCollection col2 = new NewMyCollection();
            Creat(ref col1); // Вызывает метод Creat для каждой коллекции, передавая её в качестве параметра
            Creat(ref col2);
            Journal j1 = new Journal(); // Создаёт два журнала j1 и j2 типа Journal
            col1.CollectionCountChanged += new NewMyCollection.CollectionHandler(j1.CollectionCountChanged); // Подписывает каждую коллекцию на события изменения количества элементов и ссылки на элементы в журнале
            col1.CollectionReferenceChanged += new NewMyCollection.CollectionHandler(j1.CollectionReferenceChanged);
            Journal j2 = new Journal(); // Создаёт два журнала j1 и j2 типа Journal
            col1.CollectionReferenceChanged += new NewMyCollection.CollectionHandler(j2.CollectionReferenceChanged); // Подписывает каждую коллекцию на события изменения количества элементов и ссылки на элементы в журнале
            col2.CollectionReferenceChanged += new NewMyCollection.CollectionHandler(j2.CollectionReferenceChanged);
            while (status) // бесконечный цикл, в котором пользователь выбирает одно из пяти действий
            {
                int m = 0;  
                m = Menu(m);
                switch (m)
                {
                    case 1: // Вывести список коллекций и запросить название коллекции для дальнейшей работы
                        Console.WriteLine("Коллекции: "+ col1.NameCollection + ", " + col2.NameCollection);
                        Menu(m);
                        string name = Console.ReadLine();
                        if (name == col1.NameCollection)
                            PrintCollection(col1);
                        else if (name == col2.NameCollection)
                            PrintCollection(col2);
                        else
                            Console.WriteLine("Коллекция не найдена");
                        break;
                    case 2: // Добавить элемент в выбранную коллекцию
                        Console.WriteLine("Коллекции: "+ col1.NameCollection + ", " + col2.NameCollection);
                        Menu(m);
                        name = Console.ReadLine();
                        if (name == col1.NameCollection)
                        {
                            Person a = new Person();
                            col1.AddToEnd(a.GenericPerson());
                        }
                        else if (name == col2.NameCollection)
                        {
                            Person a = new Person();
                            col2.AddToEnd(a.GenericPerson());
                        }
                        else
                        {
                            Console.WriteLine("Коллекция не найдена");
                        }    
                        break;
                    case 3: // Удалить элемент из выбранной коллекции
                        Console.WriteLine("Коллекции: "+ col1.NameCollection + ", " + col2.NameCollection);
                        Menu(m);
                        name = Console.ReadLine();
                        if (name == col1.NameCollection)
                            DelElementFromCollection(ref col1);
                        else if (name == col2.NameCollection)
                            DelElementFromCollection(ref col2);
                        else
                            Console.WriteLine("Коллекция не найдена");
                        break;
                    case 4: // Преобразовать данные в выбранной коллекции
                        Console.WriteLine("Коллекции: "+ col1.NameCollection + ", " + col2.NameCollection);
                        Menu(m);
                        name = Console.ReadLine();
                        if (name == col1.NameCollection)
                            TransformDataCollection(ref col1);
                        else if (name == col2.NameCollection)
                            TransformDataCollection(ref col2);
                        else
                        {
                            Console.WriteLine("Коллекция не найдена");
                        }    
                        break;
                        case 5: // Завершить программу
                            status = false;
                            break;
                        default:
                            Console.WriteLine("Неверный параметр.");
                            break;
                } 
            }
            Console.WriteLine("Журнал №1:"); // Выводит содержимое журналов j1 и j2
            if (j1.journal.Count() != 0)
                PrintJournal(j1);
            else
                System.Console.WriteLine("Empty");
            Console.WriteLine("Журнал №2:");
            if(j2.journal.Count() !=0) // Выводит содержимое журналов j1 и j2
                PrintJournal(j2);
            else
                System.Console.WriteLine("Empty");

            Console.Read();
        }
    }
}
