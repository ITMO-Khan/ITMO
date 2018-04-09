package markup;

import java.util.ArrayList;
import java.util.List;

public class Emphasis extends Container {
    public Emphasis(List<Markup> list) {
        super(list);
    }

    public void toMarkdown(StringBuilder out) {
        super.toMarkdown("*", out);
    }

    public void toHtml(StringBuilder out) {
        super.toHtml("em", out);
    }

    public void toTex(StringBuilder out) {
        super.toTex("emph", out);
    }
}
