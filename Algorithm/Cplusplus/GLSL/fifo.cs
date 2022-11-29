class Program
{
    typedef struct page
    {
        int pagenum;
        struct page *next;
    }Page;
    static void Main(string[] args)
    {
        bool endApp = false;
        // Display title as the C# console calculator app.
        Console.WriteLine("Console Calculator in C#\r");
        Console.WriteLine("------------------------\n");

        while (!endApp)
        {
            // Declare variables and set to empty.
            string numInput1 = "";
            string numInput2 = "";
            double result = 0;

            // Ask the user to type the first number.
            Console.Write("Type a number, and then press Enter: ");
            numInput1 = Console.ReadLine();

            double cleanNum1 = 0;
            while (!double.TryParse(numInput1, out cleanNum1))
            {
                Console.Write("This is not valid input. Please enter an integer value: ");
                numInput1 = Console.ReadLine();
            }

            // Ask the user to type the second number.
            Console.Write("Type another number, and then press Enter: ");
            numInput2 = Console.ReadLine();

            double cleanNum2 = 0;
            while (!double.TryParse(numInput2, out cleanNum2))
            {
                Console.Write("This is not valid input. Please enter an integer value: ");
                numInput2 = Console.ReadLine();
            }

            // Ask the user to choose an operator.
            Console.WriteLine("Choose an operator from the following list:");
            Console.WriteLine("\ta - Add");
            Console.WriteLine("\ts - Subtract");
            Console.WriteLine("\tm - Multiply");
            Console.WriteLine("\td - Divide");
            Console.Write("Your option? ");

            string op = Console.ReadLine();

            try
            {
                result = Calculator.DoOperation(cleanNum1, cleanNum2, op);
                if (double.IsNaN(result))
                {
                    Console.WriteLine("This operation will result in a mathematical error.\n");
                }
                else Console.WriteLine("Your result: {0:0.##}\n", result);
            }
            catch (Exception e)
            {
                Console.WriteLine("Oh no! An exception occurred trying to do the math.\n - Details: " + e.Message);
            }

            Console.WriteLine("------------------------\n");

            // Wait for the user to respond before closing.
            Console.Write("Press 'n' and Enter to close the app, or press any other key and Enter to continue: ");
            if (Console.ReadLine() == "n") endApp = true;

            Console.WriteLine("\n"); // Friendly linespacing.
        }
        return;
    }
}


//先进先出算法 
int FIFO(Page *block,int pages[PAGE_NUM],int pagenum,int blocknum)
{
    int i = 0,j = 0;
    int time = 0;
    Page *old = block,*check = NULL;
    printf("结果输出：\n");
    while(i<pagenum){
    	int exist = 0;
        check = block;//每轮重新检测内存块 
        j = 0;
        
        while(j < blocknum){
            if(pages[i]==check->pagenum)// 命中，什么都不做退出 
            {
            	exist = 1;
            	break;
			}
            check = check->next;
            j++;
        }
        if(j == blocknum){//没有命中，替换
        	exist = 0;
            old->pagenum = pages[i];//如果没有找到，当前的old结点被淘汰，更新为下一个， 
            old = old->next;
            time += 1; //缺页次数+1
        }
        
        i++;
        Page *t = block;
		for(int i = 0; i < blocknum; i ++)
		{
			printf("%d    ",t->pagenum);
			t = t->next;
    	}
    	if (!exist) printf("      F");
    	printf("\n");
    }
    return time;
}

//创建链表 
Page* creatblock(int blocknum)
{
    int i;
    Page *head = NULL,*cur = NULL,*tail = NULL;
    
    for(i = 0;i < blocknum;i++){
        if(!head){//设置头节点 
            cur = (Page*)malloc(sizeof(Page)); //新建结点 
            cur->pagenum = -1; //初始化页号 
            cur->next = NULL;  
            head = tail = cur;
        }
        else{//设置后续结点，使用尾插法 
            cur = (Page*)malloc(sizeof(Page));
            cur->pagenum = -1;
            tail->next = cur;
            tail = cur;
        }
    }
    tail->next = head;
    return head;
}
int main()
{
	//---------输入准备------------- 
    int time;
    int pages[PAGE_NUM];
    int i,blocknum,pagenum;
    Page *head=NULL;
    printf("请输入块号：\n");
    scanf("%d",&blocknum);
    head = creatblock(blocknum);
    printf("请输入待访问的页面数量：\n");
    scanf("%d",&pagenum);
    printf("请输入待访问的页面号：\n");
    for(i=0;i<pagenum;i++){
        scanf("%d",&pages[i]);
    }
    //-------------------------------
    
    time = FIFO(head,pages,pagenum,blocknum);
    printf("缺页次数：%d，中断率：%.2f\n",time,time*1.0/pagenum);
    return 0;
}