import java.io.*;
class slip4_01 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        String text = "", line;
        while ((line = br.readLine()) != null)
            text += line + "\n";
        br.close();
        String result = "";
        for (int i = text.length() - 1; i >= 0; i--) {
            char ch = text.charAt(i);
            if (Character.isUpperCase(ch))
                result += Character.toLowerCase(ch);
            else if (Character.isLowerCase(ch))
                result += Character.toUpperCase(ch);
            else
                result += ch;
        }
        System.out.println("Original File Contents:");
        System.out.println(text);
        System.out.println("Reverse Order with Changed Case:");
        System.out.println(result);
    }
}
