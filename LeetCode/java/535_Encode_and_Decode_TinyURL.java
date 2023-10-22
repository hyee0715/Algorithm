import java.util.HashMap;
import java.util.Map;

public class Codec {

    private Map<String, String> map = new HashMap<>();
    private String shortKey = "a";

    // Encodes a URL to a shortened URL.
    public String encode(String longUrl) {
        if (shortKey.length() > 1 && longUrl.charAt(longUrl.length() - 1) == 'z') {
            shortKey = shortKey + "a";
        } else {
            if (shortKey.length() == 1) {
                char c = shortKey.charAt(shortKey.length() - 1);

                shortKey = String.valueOf((char)(c + 1));
            } else {
                char c = shortKey.charAt(shortKey.length() - 1);
                shortKey = shortKey.substring(0, shortKey.length() - 2);
                shortKey = shortKey + String.valueOf((char)(c + 1));
            }
        }

        map.put(shortKey, longUrl);

        return shortKey;
    }

    // Decodes a shortened URL to its original URL.
    public String decode(String shortUrl) {
        return map.get(shortUrl);
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(url));