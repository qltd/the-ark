(function ($) {
  Drupal.behaviors.theArkColumnedText = {
    attach: function () {
      var item = $('.columned-text-item');
      if (item.length === 0) return;

      var headings = item.find('h3, h4, h5, h6');
      headings.each(function (index) {
        var self = $(this)
          , sibling = self.next();

        if (!sibling.length) return;
        var replacement = $('<div class="title-content-pair"></div>').html(self.clone());
        replacement.append(sibling.clone());
        sibling.after(replacement);
        self.remove();
        sibling.remove();
      });
    }
  };
})(jQuery);
