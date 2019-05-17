package linux.path.windows.path;


import clipboard.util.SysClipboardUtil;
-Dfile.encoding=utf-8
public class ChangePathFormat
{
    public static void main(String[] args)
    {
        String path=SysClipboardUtil.getSysClipboardText();
        System.out.println(path);
//      /d/Blog/bolg5
        if(path.matches("/[a-zA-Z](?:/.+)*"))
        {
            System.out.println("Linux地址表示方式:"+path);
            //D:\Blog\bolg5
            path=path.replaceFirst("/([a-zA-Z])", "$1:");
            path=path.replace("/", "\\");
            System.out.println("转为window类型："+path);
            SysClipboardUtil.setSysClipboardText(path);
        }
        //d:\Blog\bolg5
        else if(path.matches("[a-zA-Z]:(?:\\\\.+)*"))
        {
            System.out.println("windows地址表示方式:"+path);
            path=path.replaceFirst("([a-zA-Z]):", "/$1");
            path=path.replace("\\", "/");
            System.out.println("转为Linux类型："+path);
            SysClipboardUtil.setSysClipboardText(path);
        }
    }
}

path = "E:\PyCharmZyyFile\NoteFinance\FuturesTrade\期货合约示例1.png"


// po = ChangePathFormat()
// opo = po
// 
// --------------------- 
// 作者：蓝蓝223 
// 来源：CSDN 
// 原文：https://blog.csdn.net/qq_21808961/article/details/82628230 
// 版权声明：本文为博主原创文章，转载请附上博文链接！