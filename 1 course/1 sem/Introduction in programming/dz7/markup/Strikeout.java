package markup;

import java.util.ArrayList;
import java.util.List;

public class Strikeout extends Container {
    public Strikeout(List<Markup> list) {
        super(list);
    }

    public void toMarkdown(StringBuilder out) {
        super.toMarkdown("~", out);
    }

    public void toHtml(StringBuilder out) {
        super.toHtml("s", out);
    }

    public void toTex(StringBuilder out) {
        super.toTex("textst", out);
    }
}
