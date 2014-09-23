(function ($) {
  Drupal.behaviors.theArkRegionHeader = {
    attach: function () {
      var header = $('.l-regionwrapper--header');
      if (header.length === 0) return;
      header.headroom();
    }
  };
})(jQuery);
