(function ($) {
  Drupal.behaviors.theArkRegionHeader = {
    attach: function () {
      var header = $('.l-regionwrapper--header');
      if (header.length === 0 || !Headroom) return;
      header.removeClass('no-js');

      Headroom.options = Headroom.options || {};
      if ($('.front').length === 0) Headroom.options.offset = 40;
      else Headroom.options.offset = 200;
      header.headroom();
    }
  };
})(jQuery);
