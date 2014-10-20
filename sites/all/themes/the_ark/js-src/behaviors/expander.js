(function ($) {
  Drupal.behaviors.theArkExpander = {
    attach: function () {
      var expanders = $('.expander');
      if (expanders.length === 0) return;

      expanders.addClass('expander-collapsed');
      expanders.on('tap', function () {
        $(this).toggleClass('expander-collapsed');
        Drupal.behaviors.theArkVideo.attach();
      });
    }
  };
})(jQuery);
