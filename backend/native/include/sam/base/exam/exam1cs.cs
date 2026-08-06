using System;
using System.Runtime.InteropServices;
using System.Reflection;
using System.Text;
using DevTools;

public class Exam1
{

    /*----------------------------------------------------------------------
                          print utilities
    ----------------------------------------------------------------------*/
    public static void Print_integer(IntPtr ptr)
    {

        int n = (int)(GCHandle.FromIntPtr(ptr).Target);
        Console.Write("{0} ", n);
    }

    public static void Print_string(IntPtr ptr)
    {

        StringBuilder n = (StringBuilder)(GCHandle.FromIntPtr(ptr).Target);
        Console.Write("print_string= {0}\n", n);
    }

    /*----------------------------------------------------------------------
                          HashTable
    ----------------------------------------------------------------------*/
    public static void Test_hashtable()
    {

        int i = 0;
        IntPtr htab = new IntPtr();
        int num = 0, count = 0, key = 0;
        int[] keys = new int[10];
        StringBuilder zero = new StringBuilder("zero");
        StringBuilder one = new StringBuilder("one");
        StringBuilder two = new StringBuilder("two");
        StringBuilder three = new StringBuilder("three");

        Console.WriteLine("\nHashTable test");

        /* instance HashTable object */
        htab = vsy.HashTableBegin();
        /* set initial allocation to two objects */
        vsy.HashTableDef(htab, 2);
        /* inquire and count */
        vsy.HashTableInq(htab, ref num);
        vsy.HashTableCount(htab, ref count);
        Console.WriteLine("num = {0}, count = {1}", num, count);

        /* insert some simple "string" objects */
        vsy.HashTableInsert(htab, 3, GCHandle.ToIntPtr(GCHandle.Alloc(three)));
        vsy.HashTableInsert(htab, 0, GCHandle.ToIntPtr(GCHandle.Alloc(zero)));
        vsy.HashTableInsert(htab, 2, GCHandle.ToIntPtr(GCHandle.Alloc(two)));
        vsy.HashTableInsert(htab, 1, GCHandle.ToIntPtr(GCHandle.Alloc(one)));
        Console.Write("will call hashtableforeach\n");
        vsy.HashTableForEach(htab, Print_string);
        Console.Write("called hashtableforeach\n");

        /* count and find maximum key */
        vsy.HashTableCount(htab, ref count);
        vsy.HashTableMaxKey(htab, ref key);
        Console.WriteLine("count= {0}, max key= {1}", count, key);

        /* get all keys */
        vsy.HashTableAllKeys(htab, keys);
        for (i = 0; i < count; i++)
        {
            Console.WriteLine("key = {0}", keys[i]);
        }
        /* remove a couple */
        vsy.HashTableRemove(htab, 2);
        vsy.HashTableRemove(htab, 0);

        /* now inquire and count */
        vsy.HashTableInq(htab, ref num);
        vsy.HashTableCount(htab, ref count);
        Console.WriteLine("num = {0}, count = {1}", num, count);

        /* InitIter,NextIter traversal */
        vsy.HashTableInitIter(htab);
        for (; ; )
        {
            vsy.HashTableNextIter(htab, ref key, out IntPtr ptr);
            if (ptr == IntPtr.Zero) break;

            StringBuilder str = (StringBuilder)(GCHandle.FromIntPtr(ptr).Target);
            Console.WriteLine("key = {0}, string = {1}", key, str);
        }
        /* delete object */
        vsy.HashTableEnd(htab);
    }

    /*----------------------------------------------------------------------
                          List
    ----------------------------------------------------------------------*/
    public static void Test_list()
    {
        IntPtr list;
        int one = 1;
        int ten = 10;
        int twenty = 20;

        Console.WriteLine("\nList test");
        /* instance object */
        list = vsy.ListBegin();
        /* insert some numbers */
        vsy.ListInsert(list, 1, GCHandle.ToIntPtr(GCHandle.Alloc(one)));
        vsy.ListInsert(list, 10, GCHandle.ToIntPtr(GCHandle.Alloc(ten)));
        vsy.ListInsert(list, 20, GCHandle.ToIntPtr(GCHandle.Alloc(twenty)));
        /* ForEach facility to list contents */
        vsy.ListForEach(list, Print_integer);
        Console.WriteLine("");
        /* remove an object and list contents again */
        vsy.ListRemove(list, 10);
        vsy.ListForEach(list, Print_integer);
        Console.WriteLine("");
        /* delete object */
        vsy.ListEnd(list);
    }

    /*----------------------------------------------------------------------
                          Stack
    ----------------------------------------------------------------------*/
    public static void Test_stack()
    {
        IntPtr stack;
        int one = 1;
        int ten = 10;
        int twenty = 20;

        Console.WriteLine("\nStack test");
        /* instance object */
        stack = vsy.StackBegin();

        /* push some numbers */
        vsy.StackPush(stack, GCHandle.ToIntPtr(GCHandle.Alloc(one)));
        vsy.StackPush(stack, GCHandle.ToIntPtr(GCHandle.Alloc(ten)));
        vsy.StackPush(stack, GCHandle.ToIntPtr(GCHandle.Alloc(twenty)));
        /* ForEach facility to list contents */
        vsy.StackForEach(stack, Print_integer);
        Console.WriteLine("");
        /* pop an object off and list contents again*/
        vsy.StackPop(stack);
        vsy.StackForEach(stack, Print_integer);
        Console.WriteLine("");
        /* delete object */
        vsy.StackEnd(stack);
    }

    /*----------------------------------------------------------------------
                          Dictionary
    ----------------------------------------------------------------------*/
    public static void Test_dictionary()
    {

        IntPtr dict;
        int num = 0, count = 0;
        StringBuilder zero = new StringBuilder("zero");
        StringBuilder one = new StringBuilder("one");
        StringBuilder two = new StringBuilder("two");
        StringBuilder three = new StringBuilder("three");
        StringBuilder ithree = new StringBuilder("3");

        Console.WriteLine("\nDictionary test");

        /* instance Dictionary object */
        dict = vsy.DictionaryBegin();
        /* set initial allocation to two objects */
        vsy.DictionaryDef(dict, 2);
        /* inquire and count */
        vsy.DictionaryInq(dict, ref num);
        vsy.DictionaryCount(dict, ref count);
        Console.WriteLine("num = {0}, count = {1}", num, count);

        /* insert some simple "string" objects */
        vsy.DictionaryInsert(dict, three, GCHandle.ToIntPtr(GCHandle.Alloc(three)));
        vsy.DictionaryInsert(dict, zero, GCHandle.ToIntPtr(GCHandle.Alloc(zero)));
        vsy.DictionaryInsert(dict, two, GCHandle.ToIntPtr(GCHandle.Alloc(two)));
        vsy.DictionaryInsert(dict, one, GCHandle.ToIntPtr(GCHandle.Alloc(one)));
        /* remove a couple */
        vsy.DictionaryRemove(dict, two);
        vsy.DictionaryRemove(dict, zero);

        /* now inquire and count */
        vsy.DictionaryInq(dict, ref num);
        vsy.DictionaryCount(dict, ref count);
        Console.WriteLine("num = {0}, count = {1}", num, count);

        /* InitIter,NextIter traversal */
        vsy.DictionaryInitIter(dict);
        IntPtr ptr;
        for (; ; )
        {
            vsy.DictionaryNextIter(dict, out IntPtr iname, out ptr);
            if (ptr == IntPtr.Zero) break;

            String result = Marshal.PtrToStringAnsi(iname);
            StringBuilder str = (StringBuilder)(GCHandle.FromIntPtr(ptr).Target);
            Console.WriteLine("name = {0}, string = {1}", result, str);
        }
        /* reinsert name and lookup */
        vsy.DictionaryInsert(dict, three,
                              GCHandle.ToIntPtr(GCHandle.Alloc(ithree)));
        vsy.DictionaryLookup(dict, three, out ptr);
        StringBuilder astr = (StringBuilder)(GCHandle.FromIntPtr(ptr).Target);
        Console.WriteLine("name = {0}, string = {1}", three, astr);

        /* delete object */
        vsy.DictionaryEnd(dict);
    }

    /*----------------------------------------------------------------------
                          Set environment path
    ----------------------------------------------------------------------*/
    public static void SetEnvironmentPath()
    {
        var pathVariableName = "PATH";
        var scope = EnvironmentVariableTarget.Process;
        var oldPathVariableValue = Environment.GetEnvironmentVariable(pathVariableName, scope);
        var newPathVariableValue = oldPathVariableValue + @";${CEE_SAM_EXTERNAL_LIBRARIES_BIN_PATHS}";
        Environment.SetEnvironmentVariable(pathVariableName, newPathVariableValue, scope);
    }

    /*----------------------------------------------------------------------
                          Test and demonstrate collection objects
    ----------------------------------------------------------------------*/
    public static void Main()
    {
        SetEnvironmentPath();
        vsy.LicenseValidate(new StringBuilder(HOOPS_LICENSE.KEY));
        Test_hashtable();
        Test_list();
        Test_stack();
        Test_dictionary();
    }
}
