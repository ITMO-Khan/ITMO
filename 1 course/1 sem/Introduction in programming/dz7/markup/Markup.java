package markup;

public interface Markup {
    public void toMarkdown(StringBuilder out);
    public void toHtml(StringBuilder out);
    public void toTex(StringBuilder out);
}
