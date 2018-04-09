package markup;

import java.util.ArrayList;
import java.util.List;

public class Strong extends Container {
    public Strong(List<Markup> list) {
        super(list);
    }

    public void toMarkdown(StringBuilder out) {
        super.toMarkdown("__", out);
    }

    public void toHtml(StringBuilder out) {
        super.toHtml("strong", out);
    }

    public void toTex(StringBuilder out) {
        super.toTex("textbf", out);
    }
}
