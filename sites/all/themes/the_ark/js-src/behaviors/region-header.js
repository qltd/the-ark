(function ($) {
  Drupal.behaviors.theArkRegionHeader = {
    attach: function () {
      var header = $('.l-region--header');
      if (header.length === 0) return;
      header.headroom();
    }
  };
})(jQuery);
