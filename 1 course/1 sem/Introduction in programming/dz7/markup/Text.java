package markup;

public class Text implements Markup {
    String content;

    public Text(String text) {
        content = text;
    }

    public void toMarkdown(StringBuilder out) {
        out.append(content);
    }

    public void toHtml(StringBuilder out) {
        out.append(content);
    }

    public void toTex(StringBuilder out) {
        out.append(content);
    }
}
