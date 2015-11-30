(function ($) {
  Drupal.behaviors.theArkHeadroomJSConfig = {
    attach: function () {
      var header = $('.l-regionwrapper--header')
        , social = $('.sidebar-navigation .menu');
      if (header.length === 0 || !Headroom) return;
      header.removeClass('no-js');
      social.addClass('menu-hidden');


      Headroom.options = Headroom.options || {};
      if ($('.front').length === 0) Headroom.options.offset = 40;
      else Headroom.options.offset = 200;

      Headroom.options.onTop = function () {
        social.addClass('menu-hidden');
      };
      Headroom.options.onNotTop = function () {
        social.removeClass('menu-hidden');
      };

      header.headroom();
    }
  };
})(jQuery);
