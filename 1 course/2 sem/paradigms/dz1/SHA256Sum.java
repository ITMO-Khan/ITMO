import java.io.*;
import java.nio.*;
import java.security.*;
import java.nio.file.Paths;
import java.lang.StringBuilder;
 
 
 
public class SHA256Sum {
    public static void main(String[] args) {
            try {
                if (args.length == 0) {
                    printHash(System.in, "-");
 
                } else {
                    for (String arg : args) {
                        try (FileInputStream f = new FileInputStream(arg)) {
                            printHash(f , arg);
                        } catch (FileNotFoundException e) {
                            System.err.println("Error: File " + args[0] + "doesn't exist or can't be opened: " + e.getMessage());
                        }
                    }
                }
            } catch (NoSuchAlgorithmException e) {
                System.err.println("Error: Incorrect name of the digest algorithm: " + e.getMessage());
            } catch (IOException e) {
                System.err.println("Error: Problems with reading: " + e.getMessage());
            }
        }
 
    public static void printHash(InputStream input, String name) throws IOException, NoSuchAlgorithmException {
        DigestInputStream dig = new DigestInputStream(input, MessageDigest.getInstance("SHA-256"));
        byte[] buf = new byte[1024];
        while (dig.read(buf) != -1) {
        }
        System.out.println(digestToHexString(dig.getMessageDigest()) + " *" + name);
    }
 
    public static String digestToHexString(MessageDigest md) {
        byte[] hash = md.digest();
        StringBuilder sb = new StringBuilder();
        for (byte b : hash) {
            sb.append(String.format("%02X", b));
        }
        return sb.toString();
    }
}